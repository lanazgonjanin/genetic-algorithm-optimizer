CC = gcc
CFLAGS = -Wall -lm
EXE = GA
SRC = functions.c OF.c GA.c
 
$(EXE):$(SRC)
	$(CC) $(CFLAGS) -o $(EXE) $(SRC)
 
clean:
	rm -f $(EXE)