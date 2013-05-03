#############################################################################
# Makefile for building: ../build/DummyFTPServer
# Project:  DummyFTPServer
# Template: app
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m32 -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m32 -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I../library/qt/mkspecs/linux-g++-32 -I. -I../library/qt/include/QtCore -I../library/qt/include/QtNetwork -I../library/qt/include -I.
LINK          = g++
LFLAGS        = -m32 -Wl,-rpath,../library/qt/lib
LIBS          = $(SUBLIBS)  -L../library/qt/lib -lQtNetwork -L../library/qt/lib -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = ../library/qt/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		userlist.cpp \
		user.cpp \
		core.cpp \
		confsection.cpp \
		configuration.cpp \
		serverthread.cpp \
		ftpserver.cpp \
		workpath.cpp \
		ftpcommandlist.cpp \
		ftpcommandstor.cpp \
		ftpcommandretr.cpp \
		ftpcommand.cpp moc_core.cpp \
		moc_serverthread.cpp \
		moc_ftpserver.cpp \
		moc_ftpcommandlist.cpp \
		moc_ftpcommandstor.cpp \
		moc_ftpcommandretr.cpp \
		moc_ftpcommand.cpp
OBJECTS       = main.o \
		userlist.o \
		user.o \
		core.o \
		confsection.o \
		configuration.o \
		serverthread.o \
		ftpserver.o \
		workpath.o \
		ftpcommandlist.o \
		ftpcommandstor.o \
		ftpcommandretr.o \
		ftpcommand.o \
		moc_core.o \
		moc_serverthread.o \
		moc_ftpserver.o \
		moc_ftpcommandlist.o \
		moc_ftpcommandstor.o \
		moc_ftpcommandretr.o \
		moc_ftpcommand.o
DIST          = ../library/qt/mkspecs/common/g++.conf \
		../library/qt/mkspecs/common/unix.conf \
		../library/qt/mkspecs/common/linux.conf \
		../library/qt/mkspecs/qconfig.pri \
		../library/qt/mkspecs/features/qt_functions.prf \
		../library/qt/mkspecs/features/qt_config.prf \
		../library/qt/mkspecs/features/exclusive_builds.prf \
		../library/qt/mkspecs/features/default_pre.prf \
		../library/qt/mkspecs/features/debug.prf \
		../library/qt/mkspecs/features/default_post.prf \
		../library/qt/mkspecs/features/warn_on.prf \
		../library/qt/mkspecs/features/qt.prf \
		../library/qt/mkspecs/features/unix/thread.prf \
		../library/qt/mkspecs/features/moc.prf \
		../library/qt/mkspecs/features/resources.prf \
		../library/qt/mkspecs/features/uic.prf \
		../library/qt/mkspecs/features/yacc.prf \
		../library/qt/mkspecs/features/lex.prf \
		../library/qt/mkspecs/features/include_source_dir.prf \
		DummyFTPServer.pro
QMAKE_TARGET  = DummyFTPServer
DESTDIR       = ../build/
TARGET        = ../build/DummyFTPServer

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	@$(CHK_DIR_EXISTS) ../build/ || $(MKDIR) ../build/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: DummyFTPServer.pro  ../library/qt/mkspecs/linux-g++-32/qmake.conf ../library/qt/mkspecs/common/g++.conf \
		../library/qt/mkspecs/common/unix.conf \
		../library/qt/mkspecs/common/linux.conf \
		../library/qt/mkspecs/qconfig.pri \
		../library/qt/mkspecs/features/qt_functions.prf \
		../library/qt/mkspecs/features/qt_config.prf \
		../library/qt/mkspecs/features/exclusive_builds.prf \
		../library/qt/mkspecs/features/default_pre.prf \
		../library/qt/mkspecs/features/debug.prf \
		../library/qt/mkspecs/features/default_post.prf \
		../library/qt/mkspecs/features/warn_on.prf \
		../library/qt/mkspecs/features/qt.prf \
		../library/qt/mkspecs/features/unix/thread.prf \
		../library/qt/mkspecs/features/moc.prf \
		../library/qt/mkspecs/features/resources.prf \
		../library/qt/mkspecs/features/uic.prf \
		../library/qt/mkspecs/features/yacc.prf \
		../library/qt/mkspecs/features/lex.prf \
		../library/qt/mkspecs/features/include_source_dir.prf \
		../library/qt/lib/libQtNetwork.prl \
		../library/qt/lib/libQtCore.prl
	$(QMAKE) -spec ../library/qt/mkspecs/linux-g++-32 -unix CONFIG+=debug -o Makefile DummyFTPServer.pro
../library/qt/mkspecs/common/g++.conf:
../library/qt/mkspecs/common/unix.conf:
../library/qt/mkspecs/common/linux.conf:
../library/qt/mkspecs/qconfig.pri:
../library/qt/mkspecs/features/qt_functions.prf:
../library/qt/mkspecs/features/qt_config.prf:
../library/qt/mkspecs/features/exclusive_builds.prf:
../library/qt/mkspecs/features/default_pre.prf:
../library/qt/mkspecs/features/debug.prf:
../library/qt/mkspecs/features/default_post.prf:
../library/qt/mkspecs/features/warn_on.prf:
../library/qt/mkspecs/features/qt.prf:
../library/qt/mkspecs/features/unix/thread.prf:
../library/qt/mkspecs/features/moc.prf:
../library/qt/mkspecs/features/resources.prf:
../library/qt/mkspecs/features/uic.prf:
../library/qt/mkspecs/features/yacc.prf:
../library/qt/mkspecs/features/lex.prf:
../library/qt/mkspecs/features/include_source_dir.prf:
../library/qt/lib/libQtNetwork.prl:
../library/qt/qt/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec ../library/qt/mkspecs/linux-g++-32 -unix CONFIG+=debug -o Makefile DummyFTPServer.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/DummyFTPServer1.0.0 || $(MKDIR) .tmp/DummyFTPServer1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/DummyFTPServer1.0.0/ && $(COPY_FILE) --parents userlist.h user.h passwordtype.h mainpage.h core.h confsection.h configuration.h config.h serverthread.h ftpserver.h workpath.h ftpcommandlist.h ftpcommandstor.h ftpcommandretr.h errorexception.h ftpcommand.h .tmp/DummyFTPServer1.0.0/ && $(COPY_FILE) --parents main.cpp userlist.cpp user.cpp core.cpp confsection.cpp configuration.cpp serverthread.cpp ftpserver.cpp workpath.cpp ftpcommandlist.cpp ftpcommandstor.cpp ftpcommandretr.cpp ftpcommand.cpp .tmp/DummyFTPServer1.0.0/ && (cd `dirname .tmp/DummyFTPServer1.0.0` && $(TAR) DummyFTPServer1.0.0.tar DummyFTPServer1.0.0 && $(COMPRESS) DummyFTPServer1.0.0.tar) && $(MOVE) `dirname .tmp/DummyFTPServer1.0.0`/DummyFTPServer1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/DummyFTPServer1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_core.cpp moc_serverthread.cpp moc_ftpserver.cpp moc_ftpcommandlist.cpp moc_ftpcommandstor.cpp moc_ftpcommandretr.cpp moc_ftpcommand.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_core.cpp moc_serverthread.cpp moc_ftpserver.cpp moc_ftpcommandlist.cpp moc_ftpcommandstor.cpp moc_ftpcommandretr.cpp moc_ftpcommand.cpp
moc_core.cpp: ftpserver.h \
		serverthread.h \
		core.h \
		configuration.h \
		config.h \
		confsection.h \
		userlist.h \
		user.h \
		passwordtype.h \
		errorexception.h \
		workpath.h \
		core.h
	../library/qt/bin/moc $(DEFINES) $(INCPATH) core.h -o moc_core.cpp

moc_serverthread.cpp: core.h \
		ftpserver.h \
		serverthread.h \
		user.h \
		passwordtype.h \
		workpath.h \
		configuration.h \
		config.h \
		confsection.h \
		userlist.h \
		errorexception.h \
		serverthread.h
	../library/qt/bin/moc $(DEFINES) $(INCPATH) serverthread.h -o moc_serverthread.cpp

moc_ftpserver.cpp: serverthread.h \
		core.h \
		ftpserver.h \
		configuration.h \
		config.h \
		confsection.h \
		userlist.h \
		user.h \
		passwordtype.h \
		errorexception.h \
		workpath.h \
		ftpserver.h
	../library/qt/bin/moc $(DEFINES) $(INCPATH) ftpserver.h -o moc_ftpserver.cpp

moc_ftpcommandlist.cpp: ftpcommand.h \
		serverthread.h \
		core.h \
		ftpserver.h \
		configuration.h \
		config.h \
		confsection.h \
		userlist.h \
		user.h \
		passwordtype.h \
		errorexception.h \
		workpath.h \
		ftpcommandlist.h
	../library/qt/bin/moc $(DEFINES) $(INCPATH) ftpcommandlist.h -o moc_ftpcommandlist.cpp

moc_ftpcommandstor.cpp: ftpcommand.h \
		serverthread.h \
		core.h \
		ftpserver.h \
		configuration.h \
		config.h \
		confsection.h \
		userlist.h \
		user.h \
		passwordtype.h \
		errorexception.h \
		workpath.h \
		ftpcommandstor.h
	../library/qt/bin/moc $(DEFINES) $(INCPATH) ftpcommandstor.h -o moc_ftpcommandstor.cpp

moc_ftpcommandretr.cpp: ftpcommand.h \
		serverthread.h \
		core.h \
		ftpserver.h \
		configuration.h \
		config.h \
		confsection.h \
		userlist.h \
		user.h \
		passwordtype.h \
		errorexception.h \
		workpath.h \
		ftpcommandretr.h
	../library/qt/bin/moc $(DEFINES) $(INCPATH) ftpcommandretr.h -o moc_ftpcommandretr.cpp

moc_ftpcommand.cpp: serverthread.h \
		core.h \
		ftpserver.h \
		configuration.h \
		config.h \
		confsection.h \
		userlist.h \
		user.h \
		passwordtype.h \
		errorexception.h \
		workpath.h \
		ftpcommand.h
	../library/qt/bin/moc $(DEFINES) $(INCPATH) ftpcommand.h -o moc_ftpcommand.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

main.o: main.cpp core.h \
		ftpserver.h \
		serverthread.h \
		user.h \
		passwordtype.h \
		workpath.h \
		configuration.h \
		config.h \
		confsection.h \
		userlist.h \
		errorexception.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

userlist.o: userlist.cpp core.h \
		ftpserver.h \
		serverthread.h \
		user.h \
		passwordtype.h \
		workpath.h \
		configuration.h \
		config.h \
		confsection.h \
		userlist.h \
		errorexception.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o userlist.o userlist.cpp

user.o: user.cpp user.h \
		passwordtype.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o user.o user.cpp

core.o: core.cpp core.h \
		ftpserver.h \
		serverthread.h \
		user.h \
		passwordtype.h \
		workpath.h \
		configuration.h \
		config.h \
		confsection.h \
		userlist.h \
		errorexception.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o core.o core.cpp

confsection.o: confsection.cpp confsection.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o confsection.o confsection.cpp

configuration.o: configuration.cpp configuration.h \
		config.h \
		confsection.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o configuration.o configuration.cpp

serverthread.o: serverthread.cpp serverthread.h \
		core.h \
		ftpserver.h \
		configuration.h \
		config.h \
		confsection.h \
		userlist.h \
		user.h \
		passwordtype.h \
		errorexception.h \
		workpath.h \
		ftpcommandlist.h \
		ftpcommand.h \
		ftpcommandretr.h \
		ftpcommandstor.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o serverthread.o serverthread.cpp

ftpserver.o: ftpserver.cpp ftpserver.h \
		serverthread.h \
		core.h \
		configuration.h \
		config.h \
		confsection.h \
		userlist.h \
		user.h \
		passwordtype.h \
		errorexception.h \
		workpath.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ftpserver.o ftpserver.cpp

workpath.o: workpath.cpp workpath.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o workpath.o workpath.cpp

ftpcommandlist.o: ftpcommandlist.cpp ftpcommandlist.h \
		ftpcommand.h \
		serverthread.h \
		core.h \
		ftpserver.h \
		configuration.h \
		config.h \
		confsection.h \
		userlist.h \
		user.h \
		passwordtype.h \
		errorexception.h \
		workpath.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ftpcommandlist.o ftpcommandlist.cpp

ftpcommandstor.o: ftpcommandstor.cpp ftpcommandstor.h \
		ftpcommand.h \
		serverthread.h \
		core.h \
		ftpserver.h \
		configuration.h \
		config.h \
		confsection.h \
		userlist.h \
		user.h \
		passwordtype.h \
		errorexception.h \
		workpath.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ftpcommandstor.o ftpcommandstor.cpp

ftpcommandretr.o: ftpcommandretr.cpp ftpserver.h \
		serverthread.h \
		core.h \
		configuration.h \
		config.h \
		confsection.h \
		userlist.h \
		user.h \
		passwordtype.h \
		errorexception.h \
		workpath.h \
		ftpcommandretr.h \
		ftpcommand.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ftpcommandretr.o ftpcommandretr.cpp

ftpcommand.o: ftpcommand.cpp ftpcommand.h \
		serverthread.h \
		core.h \
		ftpserver.h \
		configuration.h \
		config.h \
		confsection.h \
		userlist.h \
		user.h \
		passwordtype.h \
		errorexception.h \
		workpath.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ftpcommand.o ftpcommand.cpp

moc_core.o: moc_core.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_core.o moc_core.cpp

moc_serverthread.o: moc_serverthread.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_serverthread.o moc_serverthread.cpp

moc_ftpserver.o: moc_ftpserver.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ftpserver.o moc_ftpserver.cpp

moc_ftpcommandlist.o: moc_ftpcommandlist.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ftpcommandlist.o moc_ftpcommandlist.cpp

moc_ftpcommandstor.o: moc_ftpcommandstor.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ftpcommandstor.o moc_ftpcommandstor.cpp

moc_ftpcommandretr.o: moc_ftpcommandretr.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ftpcommandretr.o moc_ftpcommandretr.cpp

moc_ftpcommand.o: moc_ftpcommand.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ftpcommand.o moc_ftpcommand.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

