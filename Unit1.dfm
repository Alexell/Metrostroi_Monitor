object MainForm: TMainForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'MainForm'
  ClientHeight = 316
  ClientWidth = 524
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  TextHeight = 15
  object SeparatorLabel: TLabel
    Left = 492
    Top = 203
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
  object AlexellLogo: TImage
    Left = 476
    Top = 268
    Width = 40
    Height = 40
    Cursor = crHandPoint
    Picture.Data = {
      0954506E67496D61676589504E470D0A1A0A0000000D49484452000000280000
      002808060000008CFEB86D000002C54944415478DACD984D4815511886BF9B95
      4920252D245A8941D6A676B58A285C18156AD20FAE5A18FD5074210877D5A2F0
      87282C09B14041A988A2A0A222A108DA06619841114588FDDAA23FB3DE97EF5C
      9C2EB739338EE7342F3CDC7B8F3AF33877CEF79D39996CB65562A4047C8DF307
      4993892978171C01F7D32AF8142C06470D13BE048B01DF5C020F2C824BCC7B5E
      CD4630E25AB01CAF57C04AF01DEC06E72208326F8DE43D97823C416FDEF80970
      10FCB20832E3603F38E35390B909B6802F81B1D3A257383F97C166DF82CC63B0
      11BC0A8C65410B284A8320C349500F1E06C6AA413F284B8320C3C9D3047A0263
      2C3757C1D23408E6C2AFB65926274FA9911E4F8B20735DB4B48C99CF33C06A30
      901641E689E8E479E1426A3A049951D1AFD5695F4E22C8FC04BB40F7FF1264BF
      5D17E138FFEA3CCE05ABC07A701CCCB41C8B9D673BF8E453907D7708D48816E6
      52CBF106C126F0DCB720C382CC12536139E67BD020D35476E208320BC045B0C6
      725C4E1EAE703A7D0B32B3C129B033C2F13BC001D14EE34D30977DA05DEC93E7
      36D80A3EFA103C0C8E816FE633573517C03CCB799E89769E218999B8825C517F
      109DA9EF02BF734D747513165E412E80EFB816E418CB084BCFB0199F2FFAC0B5
      D6723EDE8BBC273B5C0B322C27B532F914384BB4A3EC8970DEB360AF44983C49
      04192E647780BEC0187BF349231C16D6C906F38F3A13647E9BAB117CAA63FFE6
      E42993F0F056E1FD3CE8529029B4E4AF149D3C5516C9CF609B682FF72AC8B0FC
      708BC4D6C3B90A62F91ACEFF816BC1C4A120BF02AEFB16A65590AF8B44EF9715
      53147C24BAF914373FC02D092937C1EDB7B9A28F907553104C921BA29364ACD0
      0FF3F70733A23775B379EF4390E153E206F0D226980B274E1758EE4990E15322
      B758FEDA9F0CDB615D25BA69F4C69320C3CEC44E743E8A60A1B81664D899DAC0
      21309146C15C58551AE30A2E03733C0932AFFF00C062FEA5C305B18B00000000
      49454E44AE426082}
    OnClick = AlexellLogoClick
  end
  object RestartCheck: TCheckBox
    Left = 230
    Top = 203
    Width = 234
    Height = 17
    Caption = #1055#1077#1088#1077#1079#1072#1087#1091#1089#1082#1072#1090#1100' '#1089#1077#1088#1074#1077#1088#1072' '#1077#1078#1077#1076#1085#1077#1074#1085#1086' '#1074
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    OnClick = RestartCheckClick
  end
  object HourEdit: TEdit
    Left = 471
    Top = 201
    Width = 18
    Height = 23
    NumbersOnly = True
    TabOrder = 1
    Text = '00'
  end
  object MinEdit: TEdit
    Left = 498
    Top = 201
    Width = 18
    Height = 23
    NumbersOnly = True
    TabOrder = 2
    Text = '00'
  end
  object AutostartCheck: TCheckBox
    Left = 8
    Top = 227
    Width = 185
    Height = 17
    Hint = #1055#1088#1080' '#1079#1072#1087#1091#1089#1082#1077' '#1087#1088#1086#1075#1088#1072#1084#1084#1099' '#1089#1088#1072#1079#1091' '#1085#1072#1095#1080#1085#1072#1090#1100' '#1084#1086#1085#1080#1090#1086#1088#1080#1085#1075
    Caption = #1057#1088#1072#1079#1091' '#1085#1072#1095#1080#1085#1072#1090#1100' '#1084#1086#1085#1080#1090#1086#1088#1080#1085#1075
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 3
  end
  object HideCheck: TCheckBox
    Left = 8
    Top = 251
    Width = 185
    Height = 17
    Hint = #1055#1088#1080' '#1079#1072#1087#1091#1089#1082#1077' '#1087#1088#1086#1075#1088#1072#1084#1084#1099' '#1072#1074#1090#1086#1084#1072#1090#1080#1095#1077#1089#1082#1080' '#1089#1074#1086#1088#1072#1095#1080#1074#1072#1090#1100' '#1086#1082#1085#1086
    Caption = #1040#1074#1090#1086#1084#1072#1090#1080#1095#1077#1089#1082#1080' '#1089#1074#1086#1088#1072#1095#1080#1074#1072#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 4
  end
  object StartButton: TButton
    Left = 135
    Top = 283
    Width = 250
    Height = 25
    Caption = #1053#1072#1095#1072#1090#1100' '#1084#1086#1085#1080#1090#1086#1088#1080#1085#1075
    TabOrder = 5
    OnClick = StartButtonClick
  end
  object Servers: TListView
    Left = 8
    Top = 8
    Width = 505
    Height = 150
    Columns = <
      item
        Caption = #1057#1090#1072#1090#1091#1089
        MaxWidth = 50
      end
      item
        Caption = 'IP'
        MaxWidth = 120
        Width = 120
      end
      item
        Caption = #1055#1086#1088#1090
        MaxWidth = 60
        Width = 60
      end
      item
        Caption = #1050#1072#1088#1090#1072
        MaxWidth = 210
        Width = 210
      end
      item
        Caption = #1048#1075#1088#1086#1082#1080
        MaxWidth = 60
        Width = 60
      end>
    ReadOnly = True
    RowSelect = True
    TabOrder = 6
    ViewStyle = vsReport
    OnMouseDown = ServersMouseDown
  end
  object AddButton: TButton
    Left = 8
    Top = 164
    Width = 113
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1089#1077#1088#1074#1077#1088
    TabOrder = 7
    OnClick = AddButtonClick
  end
  object DownEdit: TLabeledEdit
    Left = 471
    Top = 225
    Width = 45
    Height = 23
    EditLabel.Width = 163
    EditLabel.Height = 23
    EditLabel.Hint = 
      #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1085#1077#1091#1076#1072#1095#1085#1099#1093' '#1087#1086#1087#1099#1090#1086#1082' '#1089#1074#1103#1079#1072#1090#1100#1089#1103'  '#1089' '#1089#1077#1088#1074#1077#1088#1086#1084','#13#1087#1088#1077#1078#1076#1077', '#1095#1077#1084' ' +
      #1086#1085' '#1073#1091#1076#1077#1090' '#1087#1077#1088#1077#1079#1072#1087#1091#1097#1077#1085'.'
    EditLabel.Caption = #1050#1086#1083'-'#1074#1086' '#1085#1077#1091#1076#1072#1095#1085#1099#1093' '#1087#1086#1087#1099#1090#1086#1082':'
    EditLabel.Font.Charset = DEFAULT_CHARSET
    EditLabel.Font.Color = clWindowText
    EditLabel.Font.Height = -12
    EditLabel.Font.Name = 'Segoe UI'
    EditLabel.Font.Style = [fsBold]
    EditLabel.ParentFont = False
    EditLabel.ParentShowHint = False
    EditLabel.ShowHint = True
    LabelPosition = lpLeft
    LabelSpacing = 59
    NumbersOnly = True
    TabOrder = 8
    Text = '1'
  end
  object UpdateInticator: TActivityIndicator
    Left = 8
    Top = 284
    IndicatorSize = aisSmall
    IndicatorType = aitRotatingSector
  end
  object AutorunCheck: TCheckBox
    Left = 8
    Top = 203
    Width = 97
    Height = 17
    Hint = #1047#1072#1087#1091#1089#1082#1072#1090#1100' '#1087#1088#1086#1075#1088#1072#1084#1084#1091' '#1074#1084#1077#1089#1090#1077' '#1089' Windows'
    Caption = #1040#1074#1090#1086#1079#1072#1087#1091#1089#1082
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 10
  end
  object LogCheck: TCheckBox
    Left = 230
    Top = 251
    Width = 106
    Height = 17
    Hint = #1047#1072#1087#1080#1089#1100' '#1074#1089#1077#1093' '#1089#1086#1073#1099#1090#1080#1081' '#1074' log.txt'
    Caption = #1051#1086#1075#1080#1088#1086#1074#1072#1085#1080#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 11
  end
  object Timer: TTimer
    Enabled = False
    Interval = 60000
    OnTimer = TimerTimer
    Left = 64
    Top = 280
  end
  object IdAntiFreeze: TIdAntiFreeze
    Left = 424
    Top = 280
  end
  object Tray: TTrayIcon
    Left = 96
    Top = 280
  end
  object PopupMenu: TPopupMenu
    AutoPopup = False
    OnPopup = PopupMenuPopup
    Left = 392
    Top = 280
    object PMenuEdit: TMenuItem
      Caption = #1048#1079#1084#1077#1085#1080#1090#1100
      OnClick = PMenuEditClick
    end
    object PMenuRestart: TMenuItem
      Caption = #1055#1077#1088#1077#1079#1072#1075#1088#1091#1079#1080#1090#1100' ('#1084#1103#1075#1082#1086')'
      OnClick = PMenuRestartClick
    end
    object PMenuShutdown: TMenuItem
      Caption = #1042#1099#1082#1083#1102#1095#1080#1090#1100' ('#1084#1103#1075#1082#1086')'
      OnClick = PMenuShutdownClick
    end
    object PMenuRemove: TMenuItem
      Caption = #1059#1076#1072#1083#1080#1090#1100
      OnClick = PMenuRemoveClick
    end
  end
end
