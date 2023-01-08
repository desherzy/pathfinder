SRC_FILES = $(wildcard src/*.c)
OBJ_FILES = $(addprefix obj/, $(notdir $(SRC_FILES:%.c=%.o)))

all: install

install: libmx/libmx.a pathfinder

pathfinder: $(OBJ_FILES)
	@clang $(CFLG) $(OBJ_FILES) -Llibmx -lmx -o $@

obj/%.o: src/%.c inc/*.h
	@clang $(CFLG) -c $< -o $@ -Iinc -Ilibmx/inc

$(OBJ_FILES): | obj

obj:
	@mkdir -p $@

libmx/libmx.a:
	@make -sC libmx
 
clean:
	@rm -rf obj

uninstall:
	@make -sC libmx $@
	@rm -rf obj
	@rm -rf pathfinder

reinstall: uninstall all