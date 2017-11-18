; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{2E7063E6-EC95-482E-A4BF-3B3A2668D4A0}
AppName=calendar
AppVersion=1.5
;AppVerName=calendar 1.5
AppPublisher=My Company, Inc.
AppPublisherURL=http://www.example.com/
AppSupportURL=http://www.example.com/
AppUpdatesURL=http://www.example.com/
DefaultDirName={pf}\calendar
DisableProgramGroupPage=yes
;OutputDir=C:\Users\Anton\Desktop\calendar\Calendarlo\main_widget_calendar
OutputBaseFilename=setup2
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "dll\main_widget_calendar.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\libwinpthread-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\MSVCP140.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\Qt5Core.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\Qt5Gui.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\Qt5PrintSupport.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\Qt5Svg.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\libgcc_s_dw2-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\libstdc++-6.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\Qt5Widgets.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\platforms\*"; DestDir: "{app}/platforms"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "dll\imageformats\*"; DestDir: "{app}/imageformats"; Flags: ignoreversion recursesubdirs createallsubdirs
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{commonprograms}\calendar"; Filename: "{app}\main_widget_calendar.exe"
Name: "{commondesktop}\calendar"; Filename: "{app}\main_widget_calendar.exe"; Tasks: desktopicon

[Run]
Filename: "{app}\main_widget_calendar.exe"; Description: "{cm:LaunchProgram,calendar}"; Flags: nowait postinstall skipifsilent

