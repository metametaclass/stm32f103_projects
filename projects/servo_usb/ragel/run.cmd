set fn=%~n1
D:\Programm\ragel6.9\ragel.exe -G2 -L -o %fn%.inc %fn%.rl
D:\Programm\ragel6.9\ragel.exe -V -o %fn%.dot %fn%.rl
