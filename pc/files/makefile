include ../build-info.mk

C = gcc
CXX = g++
LINKFLAGS = -lSDL2 -lGLEW -lGL $(_PC_LIBS)

OBJDIR = obj

CFLAGS = -I./source $(_CFLAGS) $(_PC_CFLAGS)
CXXFLAGS = -I./source $(_CXXFLAGS) $(_PC_CXXFLAGS)

HEADERS = $(_HEADERS)
SOURCES = sdl-glew-wrapper.c $(_SOURCES)
OBJ = $(SOURCES:%=$(OBJDIR)/%.o)
BIN = $name

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(LINKFLAGS) $^ -o $@

$(OBJDIR)/%.cpp.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
$(OBJDIR)/%.c.o: %.c $(HEADERS)
	$(C) $(CFLAGS) -c $< -o $@
