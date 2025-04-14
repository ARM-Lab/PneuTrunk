<?xml version="1.0" encoding="utf-8"?>
<?AutomationStudio FileVersion="4.9"?>
<SwConfiguration CpuAddress="SL1" xmlns="http://br-automation.co.at/AS/SwConfiguration">
  <TaskClass Name="Cyclic#1">
    <Task Name="Client" Source="Source.UDP.Client.prg" Memory="UserROM" Language="IEC" Debugging="true" />
    <Task Name="Narazy" Source="Source.Narazy.prg" Memory="UserROM" Language="IEC" Debugging="true" />
    <Task Name="Server" Source="Source.UDP.Server.prg" Memory="UserROM" Language="IEC" Debugging="true" />
    <Task Name="Receiver" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
    <Task Name="Sender" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
  </TaskClass>
  <TaskClass Name="Cyclic#2">
    <Task Name="Receiver1" Source="Source.RS485.Receiver.prg" Memory="UserROM" Language="IEC" Debugging="true" />
    <Task Name="test_input" Source="test_input.prg" Memory="UserROM" Language="ANSIC" AdditionalIncludeDirectories="\Logical\MATLAB_includes\R2023a\" BuildOptions="-lm -DMODEL=simulink_2_plc -DNUMST=2 -DNCSTATES=0 -DHAVESTDIO -DRT -DUSE_RTMODEL -DEXT_MODE -DEXTMODE_STATIC -DEXTMODE_STATIC_SIZE=1000000 -DON_TARGET_WAIT_FOR_START=0 -DCLASSIC_INTERFACE=1 -DALLOCATIONFCN=0 -DTID01EQ=1 -DMAT_FILE=0 -DONESTEPFCN=0 -DTERMFCN=1 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 " Debugging="false" />
  </TaskClass>
  <TaskClass Name="Cyclic#3">
    <Task Name="Sender1" Source="Source.RS485.Sender.prg" Memory="UserROM" Language="IEC" Debugging="true" />
    <Task Name="solo_reg" Source="solo_reg.prg" Memory="UserROM" Language="ANSIC" AdditionalIncludeDirectories="\Logical\MATLAB_includes\R2023a\" BuildOptions="-lm -DMODEL=pneutr2_reg_FF_stiff -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DRT -DUSE_RTMODEL -DCLASSIC_INTERFACE=1 -DALLOCATIONFCN=0 -DTID01EQ=0 -DMAT_FILE=0 -DONESTEPFCN=0 -DTERMFCN=1 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 " Debugging="false" />
  </TaskClass>
  <TaskClass Name="Cyclic#4">
    <Task Name="Identifika" Source="Source.Identifikacia.prg" Memory="UserROM" Language="IEC" Debugging="true" Disabled="true" />
    <Task Name="meranie" Source="meranie.prg" Memory="UserROM" Language="ANSIC" AdditionalIncludeDirectories="\Logical\MATLAB_includes\R2022b\" BuildOptions="-lm -DMODEL=pneutrunkMeranie -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DRT -DUSE_RTMODEL -DEXT_MODE -DEXTMODE_STATIC -DEXTMODE_STATIC_SIZE=1000000 -DON_TARGET_WAIT_FOR_START=0 -DCLASSIC_INTERFACE=1 -DALLOCATIONFCN=0 -DTID01EQ=0 -DMAT_FILE=0 -DONESTEPFCN=0 -DTERMFCN=1 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 " Debugging="false" Disabled="true" />
    <Task Name="Testing" Source="Source.Testing.prg" Memory="UserROM" Language="IEC" Debugging="true" Disabled="true" />
    <Task Name="Program" Source="Source.Program.prg" Memory="UserROM" Language="IEC" Debugging="true" />
    <Task Name="Controller" Source="Source.Controller.prg" Memory="UserROM" Language="IEC" Debugging="true" />
  </TaskClass>
  <TaskClass Name="Cyclic#5" />
  <TaskClass Name="Cyclic#6" />
  <TaskClass Name="Cyclic#7" />
  <TaskClass Name="Cyclic#8" />
  <DataObjects>
    <DataObject Name="Acp10sys" Source="" Memory="UserROM" Language="Binary" />
  </DataObjects>
  <Binaries>
    <BinaryObject Name="FWRules" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="TCData" Source="" Memory="SystemROM" Language="Binary" />
    <BinaryObject Name="udbdef" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="asfw" Source="" Memory="SystemROM" Language="Binary" />
    <BinaryObject Name="User" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="iomap" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="sysconf" Source="" Memory="SystemROM" Language="Binary" />
    <BinaryObject Name="arconfig" Source="" Memory="SystemROM" Language="Binary" />
    <BinaryObject Name="ashwd" Source="" Memory="SystemROM" Language="Binary" />
    <BinaryObject Name="Role" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="ashwac" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="Acp10map" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="acp10cfg" Source="" Memory="UserROM" Language="Binary" />
  </Binaries>
  <Libraries>
    <LibraryObject Name="runtime" Source="Libraries.runtime.lby" Memory="UserROM" Language="binary" Debugging="true" />
    <LibraryObject Name="AsUDP" Source="Libraries.AsUDP.lby" Memory="UserROM" Language="binary" Debugging="true" />
    <LibraryObject Name="asstring" Source="Libraries.asstring.lby" Memory="UserROM" Language="binary" Debugging="true" />
    <LibraryObject Name="standard" Source="Libraries.standard.lby" Memory="UserROM" Language="binary" Debugging="true" />
    <LibraryObject Name="sys_lib" Source="Libraries.sys_lib.lby" Memory="UserROM" Language="binary" Debugging="true" />
    <LibraryObject Name="brsystem" Source="Libraries.brsystem.lby" Memory="UserROM" Language="binary" Debugging="true" />
    <LibraryObject Name="dvframe" Source="Libraries.dvframe.lby" Memory="UserROM" Language="binary" Debugging="true" />
    <LibraryObject Name="AsTCP" Source="Libraries.AsTCP.lby" Memory="UserROM" Language="Binary" Debugging="false" />
    <LibraryObject Name="AsArLog" Source="Libraries.AsArLog.lby" Memory="UserROM" Language="Binary" Debugging="false" />
    <LibraryObject Name="regulatory" Source="Libraries.regulatory.lby" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <LibraryObject Name="asieccon" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="astime" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="powerlnk" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="fileio" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
  </Libraries>
</SwConfiguration>