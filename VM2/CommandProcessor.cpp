/* 
* CommandProcessor.cpp
*
* Created: 03.02.2020 01:30:44
* Author: admin
*/


#include "CommandProcessor.h"
//volatile uint8_t			CommandProcessor::thebuffer = LD_1;
// default constructor
CommandProcessor::CommandProcessor()
{
	m_CommandCounter = 1;
} //CommandProcessor

// default destructor
CommandProcessor::~CommandProcessor()
{

} //~CommandProcessor

CommandProcessor::CommandProcessor( const CommandProcessor &c )
{
	
}
CommandProcessor& CommandProcessor::operator=( const CommandProcessor &c )
{
	return *this;
}

void CommandProcessor::PickUp()
{
	//volatile uint8_t t ;
	//t =  pgm_read_byte(m_CommandCounter);
	pgm_write_byte()
	m_Command.mnemonics = pgm_read_byte(m_CommandCounter);
	m_Command.device = pgm_read_byte(m_CommandCounter+1);
	m_Command.destination_address[0] = pgm_read_byte(m_CommandCounter+2);
	m_Command.destination_address[1] = pgm_read_byte(m_CommandCounter+3);
	m_Command.source_address[0] = pgm_read_byte(m_CommandCounter+4);
	m_Command.source_address[1] = pgm_read_byte(m_CommandCounter+5);
};
void CommandProcessor::reset() 
{
	m_CommandCounter = _plc_section_start ;
}
void CommandProcessor::set(uint16_t nCommandStart) 
{
	m_CommandCounter = nCommandStart;
}

uint8_t	 CommandProcessor::execute() 
{
	// TO DO 
	// decode 
	//sCommandCode c_code;
	//PickUp(c_code) ;
	switch (m_Command.mnemonics)
	{
		case  LD_1 :
			// execute LD_1 command
			Exe_LD_1();
			break;
		case  ST_1 :
			// execute ST_1 command
			Exe_LD_1();
			break;
		default:
			;
	}
	
	return 1;
}

uint8_t	 CommandProcessor::Exe_LD_1()
{
	return 0;
}
uint8_t	 CommandProcessor::Exe_ST_1()
{
	return 0;
}
volatile uint32_t CommandProcessor::next() 
{
	m_CommandCounter = m_CommandCounter+ 5 * sizeof (uint8_t);
	return m_CommandCounter;
	//return 1;
}
volatile uint32_t CommandProcessor::previous()
{
	m_CommandCounter = m_CommandCounter- 6* sizeof (uint8_t);
	return m_CommandCounter;
	if (m_CommandCounter > NULL )
		return m_CommandCounter;
	else
		m_CommandCounter= NULL;
	return 
		m_CommandCounter;

}