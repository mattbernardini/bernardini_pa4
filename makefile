CC = gcc
CLFAGS = -g
TARGET = bank
TARGET1 = wc
OBJS1 = wordCounter.o
OBJS = main.o
ALL: bank wc
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
$(TARGET1): $(OBJS1)
	$(CC) -o $(TARGET1) $(OBJS1)
wordCounter.o: wordCounter.c
	$(CC) $(CFLAGS) -c wordCounter.c
clean:
	rm -f *.o $(TARGET)
