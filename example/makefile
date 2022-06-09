CC = g++
LINK = g++
CFLAGS = -c -Wall -pedantic
LFLAGS = -Wall -pedantic
OBJS = exampleCpp.o
EXE = exampleCpp

exampleCppRun: exampleCpp
	./$(EXE)

exampleCpp: $(OBJS)
	$(LINK) $(LFLAGS) -o $(EXE) $(OBJS)

exampleCpp.o:exampleCpp.cpp
	python3 ../firmwareVersion.py
	$(CC) $(CFLAGS) exampleCpp.cpp

clean:
	@echo Clean all auto-generated files
	rm -f $(EXE) $(OBJS)
