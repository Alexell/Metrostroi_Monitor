object MainForm: TMainForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'MainForm'
  ClientHeight = 309
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
    Top = 261
    Width = 40
    Height = 40
    Cursor = crHandPoint
    Picture.Data = {
      0954506E67496D61676589504E470D0A1A0A0000000D49484452000000280000
      002808060000008CFEB86D000000017352474200AECE1CE90000000467414D41
      0000B18F0BFC6105000000097048597300000EC300000EC301C76FA864000000
      1874455874536F667477617265005061696E742E4E45542076332E3336A9E7E2
      25000002BF4944415478DACD984D4815511886BF6B664520292D225A4542D6A6
      76B592285A1415FD8825AE5A14FD601404E2AE5A14FD10851511151414255228
      5894141441DB206E984221458899A58BCCD47A5FBE7371BADCE6CC389EE3BCF0
      C0BDE77A671EE7CEF9BE332723F13207FC8CF99D44C9C4FCFB0E701CBC48ABE0
      3B50014E18C67D09CE026740337869115C6A5EF36AD6815ED7820BC003B00AFC
      02FBC18D0882CC1723F9CCA5204F703B6FFC3C380AC62C82CC2838042EFB1464
      1E811A301418BB247A85F3D30276F81664DE80CDA0273076049C0633D220C870
      126C07AF0263EBC15D509E06418693670FB8151863B9790896A5413017FEB48D
      3231794A8DF4685A049936F39D41F3BE085481E7691164DE8A4E9E0F2EA4A642
      90E913FD599DF6E52482CC6FB00F5C9F2E41F6DB75118EF3BFCEE35CB0126C04
      A740B1E558EC3CB5E0BB4F41F6DD4EB041B430975A8E97055B40B76F41860599
      2566B1E598FDA05AA6A8ECC41164E683FB608DE5B89C3C5CE15CF12DC894808B
      606F84E33781C3A29DC69B602EF5E09CD827CF13B0130CF8103C064E8261F39E
      AB9A7B609EE53CEF453B4FA7C44C5C41AEA8BF89CED4AF81BF69155DDD848557
      900BE0A7AE0539C632C2D2D365C6CB441FB8D65ACEC77B91F764936B4186E564
      AB4C3C05CE14ED2807229CF72A382811264F1241860BD9DDE04E608CBDF98211
      0E0BEB64B5F9479D09327FCCD5083ED5B17F73F2944B7878ABF07ECEBA14640A
      2DF997884E9E4A8BE40FB04BB4977B1564587EB84562EBE15C05B17C75E57FE0
      5A307128C89F80EBBE856915641689DE2F2B2729F85A74F3296E46C063092937
      C1EDB7B9A28F90DB26219824EDA29364B0D0879902EF7953379AD73E04193E25
      6E021F6D82B970E25C032B3C09327C4AE416CB3FFB93613BACAB45378D3E7B12
      64D899D8896E46112C14D7820C3BD359D000C6D328980BAB4A5D5CC1E560B627
      41E6D35FBCA1C54D031B30530000000049454E44AE426082}
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
    Top = 218
    Width = 177
    Height = 17
    Caption = #1057#1088#1072#1079#1091' '#1085#1072#1095#1080#1085#1072#1090#1100' '#1084#1086#1085#1080#1090#1086#1088#1080#1085#1075
    TabOrder = 4
  end
  object HideCheck: TCheckBox
    Left = 8
    Top = 241
    Width = 177
    Height = 17
    Caption = #1040#1074#1090#1086#1084#1072#1090#1080#1095#1077#1089#1082#1080' '#1089#1074#1086#1088#1072#1095#1080#1074#1072#1090#1100
    TabOrder = 5
  end
  object StartButton: TButton
    Left = 143
    Top = 276
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
    Top = 277
    IndicatorSize = aisSmall
    IndicatorType = aitRotatingSector
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
    Left = 400
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
    Left = 432
    Top = 280
  end
end
