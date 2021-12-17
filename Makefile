
# UNIT_TEST_DIR = ./unit_tests

# cli.o: cli.cpp cli.hpp
# 	g++ -c -Wall -Wextra -Wpedantic cli.cpp
# 	make -C $(UNIT_TEST_DIR)
# 	make run -C $(UNIT_TEST_DIR)

# clean:
# 	rm -f cli.o

# rebuild: clean cli.o

# build_unit_tests:
# 	make -C $(UNIT_TEST_DIR)

# run_unit_tests: build_unit_tests
# 	make run -C $(UNIT_TEST_DIR)

# clean_unit_tests:
# 	make clean -C $(UNIT_TEST_DIR)

# clean_all: clean clean_unit_tests



UNIT_TEST_DIR = ./unit_tests





# Remake the static library
lib/libclis.a: obj/cli.o
	ar rcs lib/libclis.a obj/cli.o



obj/cli.o: cli.cpp cli.hpp
	g++ cli.cpp -c -Wall -Wextra -Wpedantic -o obj/cli.o


clean:
	rm -f obj/*.* lib/*.*


rebuild: clean lib/libclis.a
