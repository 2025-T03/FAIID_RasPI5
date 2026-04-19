IDIR = ../include
CC = gcc
CFLAGS = -I$(IDIR)

ODIR = obj
LDIR = ../lib

LIBS = -lm

_DEPS = main.h # list all header files here
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o  # each file in src should have a corresponding .o file
OBJ = $(patsubst %,$(ODIR)/%,$(_ODJ))

$(ODIR)/%.o: %.c $(DEPS)
  $(CC) -c -o $@ $< $(CFLAGS)

FAIID: $(OBJ)
  $(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
  rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
