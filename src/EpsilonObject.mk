##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=EpsilonObject
ConfigurationName      :=Debug
WorkspacePath          := "/home/manoj/programming/cpp/github.com/rimpo/epsilon/src"
ProjectPath            := "/home/manoj/programming/cpp/github.com/rimpo/epsilon/src"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Manoj Bisht
Date                   :=03/14/15
CodeLitePath           :="/home/manoj/.codelite"
LinkerName             :=/usr/bin/g++ 
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
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
ObjectsFileList        :="EpsilonObject.txt"
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
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++ 
CC       := /usr/bin/gcc 
CXXFLAGS :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Object.cpp$(ObjectSuffix) $(IntermediateDirectory)/Field.cpp$(ObjectSuffix) $(IntermediateDirectory)/ProcessObject.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/manoj/programming/cpp/github.com/rimpo/epsilon/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Object.cpp$(ObjectSuffix): Object.cpp $(IntermediateDirectory)/Object.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/manoj/programming/cpp/github.com/rimpo/epsilon/src/Object.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Object.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Object.cpp$(DependSuffix): Object.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Object.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Object.cpp$(DependSuffix) -MM "Object.cpp"

$(IntermediateDirectory)/Object.cpp$(PreprocessSuffix): Object.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Object.cpp$(PreprocessSuffix) "Object.cpp"

$(IntermediateDirectory)/Field.cpp$(ObjectSuffix): Field.cpp $(IntermediateDirectory)/Field.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/manoj/programming/cpp/github.com/rimpo/epsilon/src/Field.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Field.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Field.cpp$(DependSuffix): Field.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Field.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Field.cpp$(DependSuffix) -MM "Field.cpp"

$(IntermediateDirectory)/Field.cpp$(PreprocessSuffix): Field.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Field.cpp$(PreprocessSuffix) "Field.cpp"

$(IntermediateDirectory)/ProcessObject.cpp$(ObjectSuffix): ProcessObject.cpp $(IntermediateDirectory)/ProcessObject.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/manoj/programming/cpp/github.com/rimpo/epsilon/src/ProcessObject.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ProcessObject.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ProcessObject.cpp$(DependSuffix): ProcessObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ProcessObject.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ProcessObject.cpp$(DependSuffix) -MM "ProcessObject.cpp"

$(IntermediateDirectory)/ProcessObject.cpp$(PreprocessSuffix): ProcessObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ProcessObject.cpp$(PreprocessSuffix) "ProcessObject.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) ".build-debug/EpsilonObject"


