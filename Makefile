working_dir=$(shell pwd)
build_dir=${working_dir}/build
scripts_dir=${working_dir}/scripts
executable_name="vEngine"

color_red    := $(shell tput -Txterm setaf 1)
color_green  := $(shell tput -Txterm setaf 2)
color_yellow := $(shell tput -Txterm setaf 3)
color_clear  := $(shell tput -Txterm sgr0)

all: config build run

build: config
	@(echo "\n${color_green}Building ${executable_name}${color_clear}")
	@(echo "${color_yellow}Running make${color_clear}")
	@(cd ${build_dir} && make)

config:
	@(echo "\n${color_yellow}Running config${color_clear}")
	@if [ ! -d ${build_dir} ]; then mkdir ${build_dir}; fi
	@(cd ${build_dir} && cmake ..  -DDEBUG_BUILD=TRUE -DFLY_BUILD=FALSE -DRELEASE_BUILD=FALSE)

ut_config:
	@(echo "${color_yellow}Running ut_config${color_clear}")
	@if [ ! -d ${build_dir} ]; then mkdir ${build_dir}; fi
	@(cd ${build_dir} && cmake .. -DDEBUG_BUILD=TRUE -DFLY_BUILD=FALSE -DRELEASE_BUILD=FALSE -DENABLE_TESTING=TRUE)

run_ut:
	@(echo "${color_yellow}Running UTs${color_clear}")
	@${scripts_dir}/build_and_run_all_uts.sh ${build_dir}

config_fly:
	@(echo "\n${color_yellow}Running config with fly mode${color_clear}")
	@if [ ! -d ${build_dir} ]; then mkdir ${build_dir}; fi
	@(cd ${build_dir} && cmake ..  -DDEBUG_BUILD=FALSE -DFLY_BUILD=TRUE -DRELEASE_BUILD=FALSE)

config_release:
	@(echo "\n${color_yellow}Running config with release mode${color_clear}")
	@if [ ! -d ${build_dir} ]; then mkdir ${build_dir}; fi
	@(cd ${build_dir} && cmake .. -DDEBUG_BUILD=FALSE -DFLY_BUILD=FALSE -DRELEASE_BUILD=TRUE)

run:
	@(echo "\n${color_green}Running executable: ${executable_name}${color_clear}")
	@(${build_dir}/${executable_name})
	@(echo "\n${color_green}Finished successfuly!${color_clear}")

clean:
	@(echo "\n${color_yellow}Running clean${color_clear}")
	@(echo "${color_green}Cleaning ${working_dir}/${build_dir}${color_clear}")
	@rm -rf ${build_dir}
	@echo "${color_green}Done${color_clear}"