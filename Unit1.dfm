object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'MainForm'
  ClientHeight = 397
  ClientWidth = 302
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnShow = FormShow
  TextHeight = 15
  object CmdLabel: TLabel
    Left = 8
    Top = 112
    Width = 196
    Height = 15
    Caption = #1050#1086#1084#1072#1085#1076#1085#1072#1103' '#1089#1090#1088#1086#1082#1072' '#1079#1072#1087#1091#1089#1082#1072' '#1089#1077#1088#1074#1077#1088#1072':'
  end
  object SeparatorLabel: TLabel
    Left = 269
    Top = 231
    Width = 3
    Height = 15
    Caption = ':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object ActionLabel: TLabel
    Left = 8
    Top = 264
    Width = 145
    Height = 15
    Caption = #1055#1088#1080' '#1079#1072#1087#1091#1089#1082#1077' '#1087#1088#1086#1075#1088#1072#1084#1084#1099':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object AboutLabel: TLabel
    Left = 62
    Top = 375
    Width = 171
    Height = 15
    Caption = #1040#1074#1090#1086#1088': Alexell | '#1057#1072#1081#1090': alexell.ru'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object IPEdit: TLabeledEdit
    Left = 8
    Top = 24
    Width = 97
    Height = 23
    Hint = 'IP '#1074#1072#1096#1077#1075#1086' '#1089#1077#1088#1074#1077#1088#1072
    EditLabel.Width = 47
    EditLabel.Height = 15
    EditLabel.Caption = 'IP '#1072#1076#1088#1077#1089':'
    TabOrder = 0
    Text = ''
    OnKeyPress = IPEditKeyPress
  end
  object PortEdit: TLabeledEdit
    Left = 111
    Top = 24
    Width = 42
    Height = 23
    EditLabel.Width = 31
    EditLabel.Height = 15
    EditLabel.Caption = #1055#1086#1088#1090':'
    TabOrder = 1
    Text = '27015'
  end
  object IntEdit: TLabeledEdit
    Left = 159
    Top = 24
    Width = 33
    Height = 23
    EditLabel.Width = 141
    EditLabel.Height = 15
    EditLabel.Caption = #1048#1085#1090#1077#1088#1074#1072#1083' '#1087#1088#1086#1074#1077#1088#1082#1080' ('#1089#1077#1082'):'
    TabOrder = 2
    Text = '60'
  end
  object FileEdit: TLabeledEdit
    Left = 8
    Top = 72
    Width = 251
    Height = 23
    EditLabel.Width = 153
    EditLabel.Height = 15
    EditLabel.Caption = #1055#1091#1090#1100' '#1082' .exe '#1074#1072#1096#1077#1075#1086' '#1089#1077#1088#1074#1077#1088#1072':'
    TabOrder = 3
    Text = ''
  end
  object FileButton: TButton
    Left = 265
    Top = 71
    Width = 29
    Height = 25
    Caption = '...'
    TabOrder = 4
    OnClick = FileButtonClick
  end
  object CmdMemo: TMemo
    Left = 8
    Top = 133
    Width = 286
    Height = 89
    Lines.Strings = (
      'start srcds.exe -console -port 27017 -tickrate 33 -'
      'game ...')
    TabOrder = 5
    OnClick = CmdMemoClick
  end
  object RestartCheck: TCheckBox
    Left = 8
    Top = 231
    Width = 233
    Height = 17
    Caption = #1055#1077#1088#1077#1079#1072#1087#1091#1089#1082#1072#1090#1100' '#1089#1077#1088#1074#1077#1088' '#1077#1078#1077#1076#1085#1077#1074#1085#1086' '#1074
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
    OnClick = RestartCheckClick
  end
  object HourEdit: TEdit
    Left = 248
    Top = 228
    Width = 18
    Height = 23
    TabOrder = 7
    Text = '00'
  end
  object MinEdit: TEdit
    Left = 276
    Top = 228
    Width = 18
    Height = 23
    TabOrder = 8
    Text = '00'
  end
  object AutostartCheck: TCheckBox
    Left = 8
    Top = 285
    Width = 177
    Height = 17
    Caption = #1057#1088#1072#1079#1091' '#1085#1072#1095#1080#1085#1072#1090#1100' '#1084#1086#1085#1080#1090#1086#1088#1080#1085#1075
    TabOrder = 9
  end
  object HideCheck: TCheckBox
    Left = 8
    Top = 308
    Width = 233
    Height = 17
    Caption = #1040#1074#1090#1086#1084#1072#1090#1080#1095#1077#1089#1082#1080' '#1089#1074#1077#1088#1085#1091#1090#1100' '#1087#1088#1086#1075#1088#1072#1084#1084#1091
    TabOrder = 10
  end
  object StartButton: TButton
    Left = 8
    Top = 344
    Width = 286
    Height = 25
    Caption = #1053#1072#1095#1072#1090#1100' '#1084#1086#1085#1080#1090#1086#1088#1080#1085#1075
    TabOrder = 11
    OnClick = StartButtonClick
  end
  object OpenDialog: TOpenDialog
    FileName = 'srcds.exe'
    Filter = #1048#1089#1087#1086#1083#1085#1103#1077#1084#1099#1077' '#1092#1072#1081#1083#1099'|*.exe'
    Title = #1042#1099#1073#1077#1088#1080#1090#1077' '#1080#1089#1087#1086#1083#1085#1103#1077#1084#1099#1081' '#1092#1072#1081#1083' '#1089#1077#1088#1074#1077#1088#1072
    Left = 16
    Top = 176
  end
  object IdTCPClient: TIdTCPClient
    ConnectTimeout = 0
    Port = 0
    ReadTimeout = -1
    Left = 88
    Top = 176
  end
  object Timer: TTimer
    Enabled = False
    Interval = 60000
    OnTimer = TimerTimer
    Left = 144
    Top = 176
  end
  object IdAntiFreeze: TIdAntiFreeze
    Left = 208
    Top = 176
  end
  object Tray: TTrayIcon
    Left = 264
    Top = 176
  end
end
