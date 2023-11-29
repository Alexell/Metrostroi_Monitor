object MainForm: TMainForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'MainForm'
  ClientHeight = 310
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
    Left = 488
    Top = 168
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
    Top = 197
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
  object AlexellLogo: TImage
    Left = 476
    Top = 262
    Width = 40
    Height = 40
    Cursor = crHandPoint
    Picture.Data = {
      0954506E67496D61676589504E470D0A1A0A0000000D49484452000000280000
      002808060000008CFEB86D0000000467414D410000B18F0BFC61050000000970
      48597300000EC200000EC20115284A800000001874455874536F667477617265
      005061696E742E4E45542076332E3336A9E7E225000002EE4944415478DACD98
      5B884D5118C7D7605C52139307C993A8195E78E349220F23C48C5C3A4F1E6886
      88529A87538E87914BA231925014318928234491F2AA341A144D24312EE3C1ED
      B8FCFEAD75B41B33679D3DE7EC65FFEBDF77F63E6BAFEFD739FBFBD6DABBCAC4
      50369B1D97CBE5BEC4B9A65C55C504BC4580317737AD808F0933F06E19D05F41
      00493C86B00F7792F49E07B0CE1DEAD7CC30FE4DA280249D4CBC84E7E26FB885
      A4274B00945E3BC8DB4902668867069C3F887790F8A70750CAE3AD8CED080928
      75E1D524FE1C013C42681964EC45C6358506941EE26524EF8D406E27ECC523D3
      0028A9081A01B81F815C4C38876BD30028A9783600713A02A9767319CF4C0360
      41FA6B5B0BC5C3B5350441E7D302285D35B6B5F43BC81184F91CDF490BA0F4C8
      D8E2799E04542500A5B7B829E975B91C40E9076E06F2C4FF02D47ABBA8847906
      5D794200D6E325780F1EE5994B2BCF3A203F8604AC23610F631A8C6DCC359EF9
      BAF172AE791614501F18A786AC1633CD33671F5E55A9B65332A0839C44B88017
      78E655F16887733428A0831C4D388C3796307F3BDEC61CF9608011D02D8403C6
      5F3C37F01AE6F9903820637711DA38F7D51D6B57731E4FF0E47962ECCAD36362
      2A2EA076D4EF8DADD477EE9C76D8578C7D982A26FD82DA00DF4C1A50406A230D
      7CF7D49D9F48E8C40B3DF9742FEA9E6C4F1A50523B5951780AE4BB6A6357944D
      25E43D863797523CE5004ADAC8AE67CCD9C89866C2215CEDC9AD3EA97ED99724
      A0F4DBFD1A1D91715ABF553CB5A6B874ABE87EEE4E1250FA67CBCFD8E9C6164F
      BD07F2135ECBF55D4101DD78B51FBD26F1ADE1DA05B5158A2E1860252440FD05
      DAF74D4925A04B3CD5D8FB65CE30011F18FBF229AEBEE3EBC5DACDDFD76F241F
      6FEC23E4CA610096A36BC616497F514007A063DDD4ADEEBB1080929E129792EB
      4551C008880AE7389E1D0850D25362E3C0F79343BE6105661EA1970B5E050294
      B432E929F194177008E8A40125AD4CFBF14EBD624E236041EA2A99B880B30863
      03014A2FFF00019AA9508C6D798A0000000049454E44AE426082}
    OnClick = AlexellLogoClick
  end
  object IntEdit: TLabeledEdit
    Left = 467
    Top = 194
    Width = 46
    Height = 23
    EditLabel.Width = 207
    EditLabel.Height = 23
    EditLabel.Caption = #1048#1085#1090#1077#1088#1074#1072#1083' '#1087#1088#1086#1074#1077#1088#1082#1080' '#1089#1077#1088#1074#1077#1088#1086#1074' ('#1089#1077#1082'):'
    EditLabel.Font.Charset = DEFAULT_CHARSET
    EditLabel.Font.Color = clWindowText
    EditLabel.Font.Height = -12
    EditLabel.Font.Name = 'Segoe UI'
    EditLabel.Font.Style = [fsBold]
    EditLabel.ParentFont = False
    LabelPosition = lpLeft
    LabelSpacing = 13
    NumbersOnly = True
    TabOrder = 0
    Text = '60'
  end
  object RestartCheck: TCheckBox
    Left = 227
    Top = 168
    Width = 234
    Height = 17
    Caption = #1055#1077#1088#1077#1079#1072#1087#1091#1089#1082#1072#1090#1100' '#1089#1077#1088#1074#1077#1088#1072' '#1077#1078#1077#1076#1085#1077#1074#1085#1086' '#1074
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = RestartCheckClick
  end
  object HourEdit: TEdit
    Left = 467
    Top = 165
    Width = 18
    Height = 23
    NumbersOnly = True
    TabOrder = 2
    Text = '00'
  end
  object MinEdit: TEdit
    Left = 495
    Top = 165
    Width = 18
    Height = 23
    NumbersOnly = True
    TabOrder = 3
    Text = '00'
  end
  object AutostartCheck: TCheckBox
    Left = 8
    Top = 224
    Width = 177
    Height = 17
    Caption = #1057#1088#1072#1079#1091' '#1085#1072#1095#1080#1085#1072#1090#1100' '#1084#1086#1085#1080#1090#1086#1088#1080#1085#1075
    TabOrder = 4
  end
  object HideCheck: TCheckBox
    Left = 8
    Top = 247
    Width = 177
    Height = 17
    Caption = #1040#1074#1090#1086#1084#1072#1090#1080#1095#1077#1089#1082#1080' '#1089#1074#1086#1088#1072#1095#1080#1074#1072#1090#1100
    TabOrder = 5
  end
  object StartButton: TButton
    Left = 135
    Top = 277
    Width = 250
    Height = 25
    Caption = #1053#1072#1095#1072#1090#1100' '#1084#1086#1085#1080#1090#1086#1088#1080#1085#1075
    TabOrder = 6
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
    TabOrder = 7
    ViewStyle = vsReport
    OnMouseDown = ServersMouseDown
  end
  object AddButton: TButton
    Left = 8
    Top = 164
    Width = 113
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1089#1077#1088#1074#1077#1088
    TabOrder = 8
    OnClick = AddButtonClick
  end
  object DownEdit: TLabeledEdit
    Left = 467
    Top = 223
    Width = 46
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
    LabelSpacing = 56
    NumbersOnly = True
    TabOrder = 9
    Text = '1'
  end
  object UpdateInticator: TActivityIndicator
    Left = 8
    Top = 278
    IndicatorSize = aisSmall
    IndicatorType = aitRotatingSector
  end
  object AutorunCheck: TCheckBox
    Left = 227
    Top = 247
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
    TabOrder = 11
  end
  object LogCheck: TCheckBox
    Left = 347
    Top = 247
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
    TabOrder = 12
  end
  object Timer: TTimer
    Enabled = False
    Interval = 60000
    OnTimer = TimerTimer
    Left = 40
    Top = 280
  end
  object IdAntiFreeze: TIdAntiFreeze
    Left = 104
    Top = 280
  end
  object Tray: TTrayIcon
    Left = 72
    Top = 280
  end
  object PopupMenu: TPopupMenu
    AutoPopup = False
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
  object RestartTimer: TTimer
    Enabled = False
    Interval = 60000
    OnTimer = RestartTimerTimer
    Left = 424
    Top = 280
  end
end
