##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=MoPLabb4LankadeListorFUNKAR
ConfigurationName      :=Debug
WorkspacePath          := "/Users/erikberglund/Documents/CodeLiteWorkSpaceErikBerglund"
ProjectPath            := "/Users/erikberglund/Documents/CodeLiteWorkSpaceErikBerglund/MoPLabb4LankadeListorFUNKAR"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Erik Berglund
Date                   :=2016-02-19
CodeLitePath           :="/Users/erikberglund/Library/Application Support/codelite"
LinkerName             :=clang++
SharedObjectLinkerName :=clang++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
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
ObjectsFileList        :="MoPLabb4LankadeListorFUNKAR.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
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
AR       := ar rcus
CXX      := clang++
CC       := clang
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := llvm-as


##
## User defined environment variables
##
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/qtest.c$(ObjectSuffix) $(IntermediateDirectory)/queue.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/qtest.c$(ObjectSuffix): qtest.c 
	$(CC) $(SourceSwitch) "/Users/erikberglund/Documents/CodeLiteWorkSpaceErikBerglund/MoPLabb4LankadeListorFUNKAR/qtest.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qtest.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qtest.c$(PreprocessSuffix): qtest.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qtest.c$(PreprocessSuffix) "qtest.c"

$(IntermediateDirectory)/queue.c$(ObjectSuffix): queue.c 
	$(CC) $(SourceSwitch) "/Users/erikberglund/Documents/CodeLiteWorkSpaceErikBerglund/MoPLabb4LankadeListorFUNKAR/queue.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/queue.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/queue.c$(PreprocessSuffix): queue.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/queue.c$(PreprocessSuffix) "queue.c"

##
## Clean
##
clean:
	$(RM) -r ./Debug/


