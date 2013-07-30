CC=gcc

CFLAGS=-Wall -pthread -O3 -DLOG
LDFLAGS=-static

ifeq ($(dbg),1)
        CFLAGS = -Wall -pthread -DDEBUG -ggdb
endif

all: libcsoft.a

TARGET  = libcsoft.a
SOURCES = $(wildcard ./*.c)
OBJECTS = $(SOURCES:.c=.o)

.SUFFIXES : .c

%.o : %.c
	$(CC) -c $(CFLAGS) $(SOURCES)

all: $(TARGET)

#$(TARGET): $(OBJECTS)
#$(CC) $(FLAGS) $(CFLAGS) $(DEBUGFLAGS) -o $(TARGET) $(OBJECTS)


$(TARGET) : $(OBJECTS) 
	ar rcs $@ $(OBJECTS)
	@echo $(OBJECTS)

clean :
	rm -f *.o libcsoft.a

