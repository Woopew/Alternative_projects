##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Goldbach2
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\Lappy\Desktop\Skola\MOP\Workspace\Goldbach"
ProjectPath            := "C:\Users\Lappy\Desktop\Skola\MOP\Workspace\Goldbach\Goldbach2"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Lappy
Date                   :=22/02/2016
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
ObjectsFileList        :="Goldbach2.txt"
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
Objects0=$(IntermediateDirectory)/is_prime.c$(ObjectSuffix) $(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/jamt_tal.c$(ObjectSuffix) $(IntermediateDirectory)/prime_pair.c$(ObjectSuffix) 



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
$(IntermediateDirectory)/is_prime.c$(ObjectSuffix): is_prime.c $(IntermediateDirectory)/is_prime.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Lappy/Desktop/Skola/MOP/Workspace/Goldbach/Goldbach2/is_prime.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/is_prime.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/is_prime.c$(DependSuffix): is_prime.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/is_prime.c$(ObjectSuffix) -MF$(IntermediateDirectory)/is_prime.c$(DependSuffix) -MM "is_prime.c"

$(IntermediateDirectory)/is_prime.c$(PreprocessSuffix): is_prime.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/is_prime.c$(PreprocessSuffix) "is_prime.c"

$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Lappy/Desktop/Skola/MOP/Workspace/Goldbach/Goldbach2/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM "main.c"

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) "main.c"

$(IntermediateDirectory)/jamt_tal.c$(ObjectSuffix): jamt_tal.c $(IntermediateDirectory)/jamt_tal.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Lappy/Desktop/Skola/MOP/Workspace/Goldbach/Goldbach2/jamt_tal.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/jamt_tal.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/jamt_tal.c$(DependSuffix): jamt_tal.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/jamt_tal.c$(ObjectSuffix) -MF$(IntermediateDirectory)/jamt_tal.c$(DependSuffix) -MM "jamt_tal.c"

$(IntermediateDirectory)/jamt_tal.c$(PreprocessSuffix): jamt_tal.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/jamt_tal.c$(PreprocessSuffix) "jamt_tal.c"

$(IntermediateDirectory)/prime_pair.c$(ObjectSuffix): prime_pair.c $(IntermediateDirectory)/prime_pair.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Lappy/Desktop/Skola/MOP/Workspace/Goldbach/Goldbach2/prime_pair.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/prime_pair.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/prime_pair.c$(DependSuffix): prime_pair.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/prime_pair.c$(ObjectSuffix) -MF$(IntermediateDirectory)/prime_pair.c$(DependSuffix) -MM "prime_pair.c"

$(IntermediateDirectory)/prime_pair.c$(PreprocessSuffix): prime_pair.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/prime_pair.c$(PreprocessSuffix) "prime_pair.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


