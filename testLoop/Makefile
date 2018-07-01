CC = gcc
INCDIR = ./inc/
SRCDIR = ./src

OUTDIR = ./out

TARGET = $(OUTDIR)/main
CFLAGS = -I$(INCDIR)
OBJ = $(SRCDIR)/loopfor.o \
        main.o

$(TARGET):$(OBJ)
	@rm -rf $(OUTDIR)
	@mkdir $(OUTDIR)

	$(CC) -o $(TARGET) $(OBJ)

clean:
	rm -rf $(OUTDIR)
	rm -rf $(OBJ)
