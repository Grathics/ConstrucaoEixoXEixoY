object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 154
  ClientWidth = 494
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 256
    Top = 40
    Width = 31
    Height = 13
    Caption = 'Label1'
  end
  object Label2: TLabel
    Left = 256
    Top = 72
    Width = 31
    Height = 13
    Caption = 'Label2'
    Transparent = False
  end
  object Label3: TLabel
    Left = 59
    Top = 27
    Width = 12
    Height = 13
    Caption = 'Xo'
  end
  object Label4: TLabel
    Left = 58
    Top = 54
    Width = 12
    Height = 13
    Caption = 'yo'
  end
  object Label5: TLabel
    Left = 59
    Top = 81
    Width = 11
    Height = 13
    Caption = 'zo'
  end
  object Edit1: TEdit
    Left = 88
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 0
    Text = '0,0'
    OnKeyPress = Edit1KeyPress
  end
  object Edit2: TEdit
    Left = 88
    Top = 51
    Width = 121
    Height = 21
    TabOrder = 1
    Text = '0,0'
    OnKeyPress = Edit2KeyPress
  end
  object Edit3: TEdit
    Left = 88
    Top = 78
    Width = 121
    Height = 21
    TabOrder = 2
    Text = '0'
  end
  object Button1: TButton
    Left = 221
    Top = 8
    Width = 85
    Height = 25
    Caption = 'Ponto P(x,y,z)'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Edit4: TEdit
    Left = 344
    Top = 118
    Width = 121
    Height = 21
    TabOrder = 4
    Text = 'Edit4'
  end
  object Button2: TButton
    Left = 309
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 5
    OnClick = Button2Click
  end
end
