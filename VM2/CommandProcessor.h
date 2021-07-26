/* 
* CommandProcessor.h
*
* Created: 03.02.2020 01:30:45
* Author: Mustafa Dülger
*/
/*
;******************************************************************************************************************
;*   
;*    _______________________________
;*   |   |   |   |   |   |   |   |   |		m : command mnemonics
;*   | M | m6| m7| m4| m3| m2| m1| m0|      M : type of command;  either bit (M=0) or byte (M=1) operation  
;*   |___|___|___|___|___|___|___|___|      d : destination device
;*   |___|___|___|___|___|___|___|___|      s : source device
;*   |  d|  d|  d|  d| s | s | s | s |		p : destination device address
;*   |___|___|___|___|___|___|___|___|		q : source device address
;*   |   |   |   |   |   | p2| p1| p0|		
;*   |___|___|___|___|___|___|___|___|
;*   |p15|   |   |   |   |p10| p9| p8|
;*   |___|___|___|___|___|___|___|___|
;*   | q7|   |   |   |   | q2| q1| q0|		
;*   |___|___|___|___|___|___|___|___|
;*   |q15|   |   |   |   |q10| q9| q8|
;*   |___|___|___|___|___|___|___|___|
;
;


;*    _____________________________________________________________________________
;*   |   |_______|         |________|                    |_______|       |_______|  |     |                    |
;*

*/
/*

;*    _________________________________________________________________________________________________________________________________________________________________
;*   | COMMAND	    |  M   |  FUNCTION 1                      |  FUNCTION 2                      |  FUNCTION 3                      |  FUNCTION 4                      |                                
;*   |______________|______|__________________________________|__________________________________|__________________________________|__________________________________|
;*   | LD_1         |  0   |  s ---> accumulator              |  accumulator -> stack            |                                  |                                  | 
;*   |______________|______|__________________________________|__________________________________|__________________________________|__________________________________|
*/
#include <stdint.h>
#include <stddef.h>
#include <avr/io.h>
#include "avr/pgmspace.h"

#ifndef __COMMANDPROCESSOR_H__
#define __COMMANDPROCESSOR_H__	


#define _stack_size 0x0F
#define _plc_section_start 0x7FF
//volatile uint8_t  *		PROGMEM m_pCC;// = & thebuffer ;
struct sCommandCode
{
	uint8_t mnemonics;
	uint8_t device;
	uint8_t destination_address[2];
	uint8_t source_address[2];
	bool	isValid;
};
class ICommandProcessor
{
public:
	virtual void PickUp() = 0;				// pickup current command indicated by the command zaehler
	virtual void reset() = 0;
	virtual uint8_t	 execute() = 0;
};

//const char PROGMEM txtHelloWorld[]="HelloWorld!";
class CommandProcessor : public ICommandProcessor
{
//variables __flash
public:

enum e_commands{LD_1 = 1, ST_1 };
protected:
  //char shortKeyTextStim[5] PROGMEM = 'Stim';
	volatile uint8_t				m_buffer;
	volatile uint16_t 	  			m_CommandCounter;// = & thebuffer ;
	volatile sCommandCode			m_Command;

private:

//functions
public: 
	CommandProcessor();
	~CommandProcessor();
	CommandProcessor( const CommandProcessor &c );
	CommandProcessor& operator=( const CommandProcessor &c );

	void set(uint16_t nCommandStart) ;

	void PickUp() ;
	void reset() ;
	uint8_t	 execute() ;
	volatile uint32_t	next() ;
	volatile uint32_t  previous() ;
protected:
private:
	uint8_t	 Exe_LD_1();
	uint8_t	 Exe_ST_1();
}; //CommandProcessor

#endif //__COMMANDPROCESSOR_H__
