CC = gcc
CFLAGS = -Wall -Werror -ggdb -std=c99
VALGRIND = valgrind --tool=memcheck --verbose --log-file

TARGET = bank
TESTTARGET = test
OBJS = main.o account.o bank.o linkedlist.o menu.o
TESTOBJS = accountDriver.o account.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

$(TESTTARGET) : $(TESTOBJS)
	$(CC) -o $(TESTTARGET) $(TESTOBJS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

account.o: account.c
	$(CC) $(CFLAGS) -c account.c

bank.o: bank.c
	$(CC) $(CFLAGS) -c bank.c

linkedlist.o: linkedlist.c
	$(CC) $(CFLAGS) -c linkedlist.c

accountDriver.o: accountDriver.c
	$(CC) $(CFLAGS) -c accountDriver.c

menu.o: menu.c
	$(CC) $(CFLAGS) -c menu.c

testall: testCreateAccount testCreateAccountWithDefaults

testCreateAccount: $(TESTTARGET)
	./test 0 inputs/createAccount > outputs/createAccount
	diff expected/createAccount outputs/createAccount
	$(VALGRIND)=outputs/valgrindLogFile ./test 0 inputs/createAccount	

testCreateAccountWithDefaults: $(TESTTARGET)
	./test 1 < inputs/createAccountWithDefaults > outputs/createAccountWithDefaults
	diff expected/createAccountWithDefaults outputs/createAccountWithDefaults
	$(VALGRIND)=outputs/valgrindLogFile ./test 1 < inputs/createAccountWithDefaults	

clean:
	rm -f *.o $(TARGET) $(TESTTARGET) outputs/*
