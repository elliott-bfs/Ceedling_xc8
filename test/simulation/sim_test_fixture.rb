require 'rbconfig'
is_windows = (RbConfig::CONFIG['host_os'] =~ /mswin|mingw|cygwin/)
OUT_FILE = "build/test/results/out.txt"
File.delete OUT_FILE if File.exists? OUT_FILE
if is_windows
	var = IO.popen("'#{ENV['MPLABX_ROOT']}/mplab_platform/bin/mdb.bat' ./test/simulation/sim_instructions.script")
else
	var = IO.popen("'#{ENV['MPLABX_ROOT']}/mplab_ide/bin/mdb.sh' ./test/simulation/sim_instructions.script")
end
Process.wait
if File.exists? OUT_FILE
    file_contents = File.read OUT_FILE
    print file_contents
end