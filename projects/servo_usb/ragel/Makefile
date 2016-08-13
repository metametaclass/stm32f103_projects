all: servo_command_line.inc servo_command_line.elf servo_command_line.dot

%.dot: %.rl
	ragel -V -o $@ $<

%.inc: %.rl
	ragel -G2 -L -o $@ $<

%.elf: %.c %.inc
	gcc -o $@ $<

