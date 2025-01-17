progname=exercise_06_43
CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++03 -g3

SOURCES:=$(wildcard *.cpp)
PREPROCS:=$(patsubst %.cpp,%.ii,$(SOURCES))
ASSEMBLES:=$(patsubst %.cpp,%.s,$(SOURCES))
OBJS:=$(patsubst %.cpp,%.o,$(SOURCES))

TEST_INPUTS:=$(wildcard test*.input)
TESTS:=$(patsubst %.input,%,$(TEST_INPUTS))

qa: $(TESTS)

test%: $(progname)
	./$< < $@.input > $@.output 2>/dev/null || echo "Negative case..."
	diff $@.output $@.expected > /dev/null && echo "$@ PASSED" || echo "$@ FAILED"

$(progname): $(OBJS) | .gitignore
	$(CXX) $(CXXFLAGS)    $^ -o $@

%.ii: %.cpp 
	$(CXX) $(CXXFLAGS) -E $< -o $@
	
%.s: %.ii 
	$(CXX) $(CXXFLAGS) -S $< -o $@

%.o: %.s 
	$(CXX) $(CXXFLAGS) -c $< -o $@

.gitignore:
	echo $(progname) > .gitignore
	
clean:
	rm -rf  *.s *.ii *.o $(progname) .gitignore *output

.PRECIOUS:  $(PREPROCS) $(ASSEMBLES)
.SECONDARY: $(PREPROCS) $(ASSEMBLES)

