TEMPLATE = subdirs

SUBDIRS += \
	CourseLib \
        UnitTest\
	Game \


CourseLib.subdir = Course/CourseLib
Game.depends = CourseLib
