CC=gcc
CCFLAGS= -Wall -Werror -g 
LIBFLAGS= 
SRC= experiment.c file_struct.c pile_char.c xmlReader.c schedule.c main.c
SRC_TEST= experiment.c file_struct.c pile_char.c main_test.c
OBJ= $(SRC:.c=.o)
OBJ_TEST=$(SRC_TEST:.c=.o)
EXEC= xmlChecker
EXEC2= xmlTest


all: $(EXEC)
all: $(EXEC2)

$(EXEC): $(OBJ)
	$(CC)  $^ -o $@  $(LIBFLAGS)
$(EXEC2): $(OBJ_TEST)
	$(CC)  $^ -o $@  $(LIBFLAGS)

%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

.depends:
	$(CC) -MM $(SRC) > .depends
	$(CC) -MM $(SRC_TEST) > .depends

test: $(OBJ_TEST) 
	$(CC)  $^ -o $@  $(LIBFLAGS)	


-include .depends

clean:
	rm -f $(OBJ) $(EXEC) test *.*~
	rm -f $(OBJ_TEST) $(EXEC2) test *.*~
