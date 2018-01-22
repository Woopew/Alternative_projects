##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=labb4
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\Lappy\Desktop\Skola\MOP\Workspace\Goldbach"
ProjectPath            := "C:\Users\Lappy\Desktop\Skola\MOP\Workspace\Goldbach\labb4"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Lappy
Date                   :=23/02/2016
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="labb4.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/labb4_qtest.c$(ObjectSuffix) $(IntermediateDirectory)/labb4_queue.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/labb4_qtest.c$(ObjectSuffix): ../../../labb4/qtest.c $(IntermediateDirectory)/labb4_qtest.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Lappy/Desktop/Skola/MOP/labb4/qtest.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/labb4_qtest.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/labb4_qtest.c$(DependSuffix): ../../../labb4/qtest.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/labb4_qtest.c$(ObjectSuffix) -MF$(IntermediateDirectory)/labb4_qtest.c$(DependSuffix) -MM "../../../labb4/qtest.c"

$(IntermediateDirectory)/labb4_qtest.c$(PreprocessSuffix): ../../../labb4/qtest.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/labb4_qtest.c$(PreprocessSuffix) "../../../labb4/qtest.c"

$(IntermediateDirectory)/labb4_queue.c$(ObjectSuffix): ../../../labb4/queue.c $(IntermediateDirectory)/labb4_queue.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Lappy/Desktop/Skola/MOP/labb4/queue.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/labb4_queue.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/labb4_queue.c$(DependSuffix): ../../../labb4/queue.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/labb4_queue.c$(ObjectSuffix) -MF$(IntermediateDirectory)/labb4_queue.c$(DependSuffix) -MM "../../../labb4/queue.c"

$(IntermediateDirectory)/labb4_queue.c$(PreprocessSuffix): ../../../labb4/queue.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/labb4_queue.c$(PreprocessSuffix) "../../../labb4/queue.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


