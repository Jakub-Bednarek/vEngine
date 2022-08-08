build_dir="build"
working_dir=$(shell pwd)
executable_name="vEngine"

color_red    := $(shell tput -Txterm setaf 1)
color_green  := $(shell tput -Txterm setaf 2)
color_yellow := $(shell tput -Txterm setaf 3)
color_clear 	 := $(shell tput -Txterm sgr0)

all: clean config
	@(echo "\n${color_yellow}Running make${color_clear}")
	@(cd ${build_dir} && make)
	@(echo "\n${color_green}Running executable: ${executable_name}${color_clear}")
	@(./${build_dir}/${executable_name})

config: clean
	@(echo "\n${color_yellow}Running config${color_clear}")
	@mkdir ${build_dir}
	@(cd ${build_dir} && cmake ..)

clean:
	@(echo "\n${color_yellow}Running clean${color_clear}")
	@(echo "${color_green}Cleaning ${working_dir}/${build_dir}${color_clear}")
	@rm -rf ${build_dir}
	@echo "${color_green}Done${color_clear}"