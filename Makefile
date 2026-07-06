CC      = gcc
TARGET  = string_util
LIB     = libstring_utils.a

SRCS    = main.c string_utils.c
OBJS    = main.o string_utils.o
LIB_OBJ = string_utils.o


all: $(TARGET) $(LIB)

$(TARGET): main.o $(LIB)
	$(CC) -o $@ main.o $(LIB)

$(LIB): $(LIB_OBJ)
	ar rcs $@ $(LIB_OBJ)

%.o: %.c string_utils.h
	$(CC) -c $< -o $@

clean:
	rm -f $(TARGET) $(LIB) $(OBJS)

.PHONY: all clean