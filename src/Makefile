OBJDIR=../obj

EXECUTABLE=../picoblaze

CXXFLAGS=-c -I.. -Wall -O3 -fomit-frame-pointer
GUI_CXXFLAGS=$(CXXFLAGS) $(shell wx-config --cxxflags)
CORE_CXXFLAGS=$(CXXFLAGS)

LDFLAGS=$(shell wx-config --libs)

CORE_SOURCES=cpu/cpu.cpp \
		cpu/disasm.cpp \
		cpu/fileloader.cpp \
		cpu/io/incontroller.cpp \
		cpu/io/outcontroller.cpp \
		cpu/io/output.cpp \
		cpu/internals/decoder.cpp \
		cpu/internals/instruction.cpp \
		cpu/internals/instructions.cpp \
		cpu/internals/flags.cpp \
		cpu/internals/stack.cpp

GUI_SOURCES=gui/Start.cpp \
		gui/MainWindow.cpp \
		gui/MainWindowFunc.cpp \
		gui/CpuThread.cpp \
		gui/AboutWindow.cpp \
		gui/components/KeyboardWindow.cpp \
		gui/components/LedsWindow.cpp \
		gui/components/SwitchWindow.cpp \
		gui/components/TermWindow.cpp \
		gui/components/TimerWindow.cpp

SOURCES=$(CORE_SOURCES) $(GUI_SOURCES)

CORE_HEADERS=cpu/cpu.h \
		cpu/disasm.h \
		cpu/fileloader.h \
		cpu/io/incontroller.h \
		cpu/io/outcontroller.h \
		cpu/io/output.h \
		cpu/internals/flags.h \
		cpu/internals/instruction.h \
		cpu/internals/instructions.h \
		cpu/internals/opcodes.h \
		cpu/internals/stack.h

GUI_HEADERS=wx_pch.h \
		gui/Start.h \
		gui/MainWindow.h \
		gui/CpuThread.h \
		gui/AboutWindow.h \
		gui/components/KeyboardWindow.h \
		gui/components/LedsWindow.h \
		gui/components/SwitchWindow.h \
		gui/components/TermWindow.h \
		gui/components/TimerWindow.h

HEADERS=$(CORE_HEADERS) $(GUI_HEADERS)

CORE_OBJECTS=$(patsubst %,$(OBJDIR)/%,$(CORE_SOURCES:.cpp=.o))
GUI_OBJECTS=$(patsubst %,$(OBJDIR)/%,$(GUI_SOURCES:.cpp=.o))
OBJECTS=$(CORE_OBJECTS) $(GUI_OBJECTS)

all: $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS) $(LDFLAGS)

$(OBJDIR)/cpu/%.o: cpu/%.cpp $(CORE_HEADERS)
	mkdir -p $(@D)
	$(CXX) -o $@ $(CORE_CXXFLAGS) $< $(INCLUDES)

$(OBJDIR)/gui/%.o: gui/%.cpp $(HEADERS)
	mkdir -p $(@D)
	$(CXX) -o $@ $(GUI_CXXFLAGS) $< $(INCLUDES)

.PHONY: all clean

