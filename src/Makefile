Target		= display
CXX         	= gcc
ODIR		= obj
SRC		=$(wildcard *.c)
DIR		=$(notdir $(SRC))
OBJ 		= $(patsubst %.c, %.o, $(DIR))
$(Target): $(OBJ)
	$(CXX) $^ -o $@ -g -rdynamic 

.PHONY:clean
clean:
	rm -rf *.o
	rm -rf $(Target)

.PHONY: enable-i2c
enable-i2c:
	sudo raspi-config nonint do_i2c 1

.PHONY: install
install: enable-i2c

