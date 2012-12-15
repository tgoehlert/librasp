CC := clang
PKGS := ...
LIBNAME := rasp
SRCDIR := src
BUILDDIR := build
CFLAGS := -g -Wall -fPIC
#LIBS := `pkg-config --libs $(PKGS)`
TARGET := lib$(LIBNAME).so
LDFLAGS := -shared -Wl,-soname=$(TARGET)
 
SRCEXT = cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
#DEPS := $(OBJECTS:.o=.deps)
 
$(TARGET): $(OBJECTS)
	@echo " Linking..."; $(CC) $(LDFLAGS) $^ -o $(TARGET) $(LIBS)
 
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " CC $<"; $(CC) $(CFLAGS) -MD -c -o $@ $<

install:
	@echo " Installing...";
	@mkdir -p /usr/include/$(LIBNAME)
	@cp src/*.h** /usr/include/$(LIBNAME)
	@cp $(TARGET) /usr/lib/

clean:
	@echo " Cleaning..."; $(RM) -r $(BUILDDIR) $(TARGET)

#-include $(DEPS)
 
.PHONY: clean
.PHONY: install
