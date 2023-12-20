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
      002808060000008CFEB86D000002C54944415478DACD984D4815511886BFDB7F
      0452D222A25524646D6A672B89A485516129FDE0AA456185621084BB6AD1C50A
      29AC88B0A0202989A2A0A2A2A008DA0AA1984211468895658BFECC7A5FBE7373
      BCD89C993B9EE3BCF070EF3DEACCE3DC39DF77E664B2D94B122373C1B7387F90
      349998828FC011F034AD82DDA0041C358CFA129C0D8E830EF0CC22B8DCBCE7D5
      AC0503AE0517E1F52628033FC05E70318220F3DE483E7629C8135CC91B6F0107
      C16F8B2033021AC0599F82CC3DB00D7C0D8C9D11BDC2F9B901AA7D0B329D6013
      781B183B009AC1F43408329C045BC1F3C0D87AD00E8AD320C870F2EC06970363
      2C37B7C08A3408E6C2AFB649C6264F91911E498B207347B4B40C9BCFD3403978
      921641E6A5E8E479ED426A32049941D1AFD5695F4E22C8FC0275A06DAA04D96F
      2B221CE77F9DC7B96029D800B26086E558EC3C3BC1679F82ECBB3DA052B43017
      598ED70536833EDF820C0B324BCC52CB313F821A99A4B21347905908AE83B596
      E372F2708573CEB720330B9C067B221CBF15348A761A6F82B9D48393629F3C0F
      C07630E443F0303806BE9BCF5CD55C03F32DE77925DA797A2466E20A7245FD49
      74A67E08FCCE6DD1D54D587805B9007EE85A90632C232C3DBD667C81E803D73A
      CBF9782FF29E6C752DC8B09C54C9D853E04CD18EB22FC279CF83FD1261F22411
      64B890DD05AE06C6D89B4F19E1B0B04ED6987FD49920F3C75C8DE0531DFB3727
      4FB18487B70AEFE72E9782CC444BFE65A293A7D422F905EC10EDE55E0519961F
      6E91D87A3857412C5FBDF93F702D983814E457C075DFE2B40AF27589E8FDB2BA
      40C117A29B4F71F313DC97907213DC7E9B27FA08B9A500C124B92B3A498627FA
      61FEFE6046F4A66E32EF7D08327C4ADC08DED80473E1C4B90056791264F894C8
      2D9671FB93613BAC6B44378DDE791264D899D889FE4915B205EC529061673A01
      0E81D1340AE6C2AA521B57702598E34990E9FF0BA14108B49FB9771200000000
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
