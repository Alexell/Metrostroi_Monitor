object MainForm: TMainForm
  Left = 0
  Top = 0
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
    TabOrder = 2
    Text = '00'
  end
  object MinEdit: TEdit
    Left = 495
    Top = 165
    Width = 18
    Height = 23
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
        AutoSize = True
        Caption = 'IP'
      end
      item
        AutoSize = True
        Caption = #1055#1086#1088#1090
      end>
    ReadOnly = True
    RowSelect = True
    TabOrder = 7
    ViewStyle = vsReport
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
    TabOrder = 9
    Text = '1'
  end
  object UpdateInticator: TActivityIndicator
    Left = 127
    Top = 165
    IndicatorSize = aisSmall
    IndicatorType = aitRotatingSector
  end
  object Timer: TTimer
    Enabled = False
    Interval = 60000
    OnTimer = TimerTimer
    Left = 456
    Top = 280
  end
  object IdAntiFreeze: TIdAntiFreeze
    Top = 280
  end
  object Tray: TTrayIcon
    Left = 496
    Top = 280
  end
end
