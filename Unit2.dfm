object ServerAddForm: TServerAddForm
  Left = 0
  Top = 0
  Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1089#1077#1088#1074#1077#1088
  ClientHeight = 261
  ClientWidth = 304
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poMainFormCenter
  TextHeight = 15
  object CmdLabel: TLabel
    Left = 8
    Top = 105
    Width = 196
    Height = 15
    Caption = #1050#1086#1084#1072#1085#1076#1085#1072#1103' '#1089#1090#1088#1086#1082#1072' '#1079#1072#1087#1091#1089#1082#1072' '#1089#1077#1088#1074#1077#1088#1072':'
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
    Width = 50
    Height = 23
    EditLabel.Width = 31
    EditLabel.Height = 15
    EditLabel.Caption = #1055#1086#1088#1090':'
    TabOrder = 1
    Text = '27015'
  end
  object FileEdit: TLabeledEdit
    Left = 8
    Top = 72
    Width = 251
    Height = 23
    EditLabel.Width = 153
    EditLabel.Height = 15
    EditLabel.Caption = #1055#1091#1090#1100' '#1082' .exe '#1074#1072#1096#1077#1075#1086' '#1089#1077#1088#1074#1077#1088#1072':'
    TabOrder = 2
    Text = ''
  end
  object FileButton: TButton
    Left = 265
    Top = 71
    Width = 29
    Height = 25
    Caption = '...'
    TabOrder = 3
    OnClick = FileButtonClick
  end
  object CmdMemo: TMemo
    Left = 8
    Top = 125
    Width = 286
    Height = 89
    Lines.Strings = (
      'start srcds.exe -console -port 27017 -tickrate 33 -'
      'game ...')
    TabOrder = 4
    OnClick = CmdMemoClick
  end
  object SaveButton: TButton
    Left = 8
    Top = 225
    Width = 135
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    TabOrder = 5
    OnClick = SaveButtonClick
  end
  object CancelButton: TButton
    Left = 161
    Top = 225
    Width = 135
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 6
  end
  object OpenDialog: TOpenDialog
    FileName = 'srcds.exe'
    Filter = #1048#1089#1087#1086#1083#1085#1103#1077#1084#1099#1077' '#1092#1072#1081#1083#1099'|*.exe'
    Title = #1042#1099#1073#1077#1088#1080#1090#1077' '#1080#1089#1087#1086#1083#1085#1103#1077#1084#1099#1081' '#1092#1072#1081#1083' '#1089#1077#1088#1074#1077#1088#1072
    Left = 248
    Top = 8
  end
end
