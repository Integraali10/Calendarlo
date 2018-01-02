; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{2E7063E6-EC95-482E-A4BF-3B3A2668D4A0}
AppName=Calendarlo
AppVersion=1.9999
;AppVerName=Calendarlo 1.9999
AppPublisher=ITMO Students & Co.
AppPublisherURL=https://github.com/Integraali10
AppSupportURL=http://www.example.com/
AppUpdatesURL=https://github.com/Integraali10/Calendarlo
DefaultDirName={pf}\Calendarlo
DisableProgramGroupPage=yes
OutputDir=.
OutputBaseFilename=setupinstall
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "release\main_widget_calendar.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "release\version.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "release\Qt5Core.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "release\Qt5Gui.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "release\Qt5PrintSupport.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "release\Qt5Svg.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\libwinpthread-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\libgcc_s_dw2-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\libstdc++-6.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\libicuin58.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\libicuio58.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\libicuuc58.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\libicudt58.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\zlib1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\libgcc_s_seh-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\libglib-2.0-0.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\libpng16-16.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\libharfbuzz-0.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\libfreetype-6.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\libbz2-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\libintl-8.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\libiconv-2.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\libgraphite2.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\libpcre-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "dll\libffi-6.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "release\Qt5Widgets.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "release\platforms\*"; DestDir: "{app}/platforms"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "release\imageformats\*"; DestDir: "{app}/imageformats"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "release\printsupport\*"; DestDir: "{app}/printsupport"; Flags: recursesubdirs createallsubdirs
Source: "release\translations\*"; DestDir: "{app}/translations"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "release\iconengines\*"; DestDir: "{app}/iconengines"; Flags: ignoreversion recursesubdirs createallsubdirs
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{commonprograms}\Calendarlo"; Filename: "{app}\main_widget_calendar.exe"
Name: "{commondesktop}\Calendarlo"; Filename: "{app}\main_widget_calendar.exe"; Tasks: desktopicon

[Run]
Filename: "{app}\main_widget_calendar.exe"; Description: "{cm:LaunchProgram,calendar}"; Flags: nowait postinstall skipifsilent

