all: libmx

libmx:
	mkdir obj
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -Iinc -c src/*.c
	mv *.o obj/
	ar -rc libmx.a obj/*.o
	ranlib libmx.a

clean:
	rm -rf obj
	
uninstall:
	rm -rf obj
	rm -rf libmx.a

reinstall:
	make uninstall
	make
