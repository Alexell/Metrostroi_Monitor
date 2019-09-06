object LogForm: TLogForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1051#1086#1075' '#1089#1086#1073#1099#1090#1080#1081
  ClientHeight = 115
  ClientWidth = 399
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnHide = FormHide
  PixelsPerInch = 96
  TextHeight = 13
  object Log: TMemo
    Left = 0
    Top = 0
    Width = 399
    Height = 115
    Align = alClient
    ReadOnly = True
    TabOrder = 0
  end
end
