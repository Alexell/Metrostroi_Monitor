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
      002808060000008CFEB86D0000000467414D410000B18F0BFC61050000000970
      48597300000EC100000EC101B8916BED0000001874455874536F667477617265
      005061696E742E4E45542076332E3336A9E7E225000002ED4944415478DACD98
      5B884D5118C7D7605C52139307C993A8195E78E349220F23C48C5C3A2FC703CD
      10514AF38687914BA23192384511938832421429AF4AA341D14412E3321EDC8E
      CBEFDF5A47BB3173D6D973CE5EF6BFFE7D67EFB3F6FA7E9DB3BF6FADBDAB4C0C
      65B3D971B95CEE4B9C6BCA55554CC05B84DD40DE4D2BE063C20CBC4706F45710
      40128F21ECC79D24BDE701AC7387FA35338C7F9328204927132FE1B9F81B6E21
      E9A91200A5D70EF276928019E29901E70FE11D24FEE90194F2782B633B42024A
      5D7835893F47008F125A06197B91714DA101A5877819C97B2390DB09FBF0C834
      004A2A824600EE47201713CEE1DA34004A2A9E0D409C8E40AADD5CC633D30058
      90FEDAD642F1706D0D41D0F9B4004A578D6D2DFD0E7204613EC777D202283D32
      B6789E2701550940E92D6E4A7A5D2E0750FA819B813CF9BF00B5DE2E2A619E41
      579E1080F57809DE8B4779E6D2CAB30EC88F2101EB48D8C39806631B738D67BE
      6EBC9C6B9E0505D407C6A921ABC54CF3CCD9875755AAED940CE82027112EE005
      9E79553CDAE11C0B0AE82047138EE08D25CCDF8EB731473E186004740BE1A0F1
      17CF0DBC86793E240EC8D85D8436CE7D75C7DAD59CC7133C799E18BBF2F49898
      8A0BA81DF57B632BF59D3BA71DF615631FA68A49BFA036C03793061490DA4803
      DF3D75E727123AF1424F3EDD8BBA27DB930694D44E56149E02F9AEDAD8156553
      09798FE3CDA5144F39809236B2EB19733632A6997018577B72AB4FAA5FF62509
      28FD76BF4647649CD66F154FAD292EDD2ABA9FBB930494FED9F23376BAB1C553
      EF81FC84D7727D575040375EED47AF497C6BB876416D85A20B06580909507F81
      F67D535209E8124F35F67E99334CC007C6BE7C8AABEFF87AB176F3F7F51BC9C7
      1BFB08B9721880E5E89AB145D25F14D001E8583775ABFB2E04A0A4A7C4A5E47A
      51143002A2C2398167070294F494D838F0FDE4906F58819947E8E58257810025
      AD4C7A4ACC790187804E1A50D2CA7400EFD42BE6340216A4AE92890B388B3036
      10A0F4F20FA59AA8A28D2E2FD20000000049454E44AE426082}
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
