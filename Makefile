LDFLAGS += -L$(DIR)/lib/linux '-Wl,-R/usr/local/lib'

all:
	`icu-config --cxx --cxxflags --cppflags --ldflags` $(LDFLAGS) -o test test_different_locale.c

clean:
	rm test
