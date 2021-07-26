
K2ps.dll: dlldata.obj K2_p.obj K2_i.obj
	link /dll /out:K2ps.dll /def:K2ps.def /entry:DllMain dlldata.obj K2_p.obj K2_i.obj \
		kernel32.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \
.c.obj:
	cl /c /Ox /DREGISTER_PROXY_DLL \
		$<

clean:
	@del K2ps.dll
	@del K2ps.lib
	@del K2ps.exp
	@del dlldata.obj
	@del K2_p.obj
	@del K2_i.obj
