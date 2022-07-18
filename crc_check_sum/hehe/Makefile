
CFLAGS = -w -Wall -O2
SRCS = serial_checksum.c  -lpthread
PROG = tests
OPENCV = `pkg-config --cflags --libs opencv`
LIBS = $(OPENCV)
$(PROG):$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)
	$(./PROG)
