TARGET=assembler
CC=gcc
SRC_DIR=./
SRC=$(shell find $(SRC_DIR) -type f -name "*.c")
OBJS := $(addsuffix .o,$(basename $(SRC)))

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@ -g 


clean:
	$(RM) $(OBJS)


