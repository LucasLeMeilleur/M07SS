object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 593
  ClientWidth = 1104
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object BevelCmd: TBevel
    Left = 32
    Top = 144
    Width = 313
    Height = 313
  end
  object BevelJoystick: TBevel
    Left = 424
    Top = 144
    Width = 313
    Height = 313
  end
  object LabelInfoCmd: TLabel
    Left = 352
    Top = 24
    Width = 21
    Height = 13
    Caption = 'Test'
  end
  object LabelDeg: TLabel
    Left = 98
    Top = 95
    Width = 183
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = '180 deg'
  end
  object LabelVitesse: TLabel
    Left = 424
    Top = 95
    Width = 313
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = '50 cm/s'
  end
  object LabelHauteur: TLabel
    Left = 95
    Top = 511
    Width = 187
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = '50 cm'
  end
  object ShapeJoy: TShape
    Left = 573
    Top = 293
    Width = 15
    Height = 15
    Shape = stCircle
    OnMouseDown = ShapeJoyMouseDown
    OnMouseMove = ShapeJoyMouseMove
    OnMouseUp = ShapeJoyMouseUp
  end
  object ButDeg: TButton
    Left = 32
    Top = 56
    Width = 57
    Height = 57
    Caption = 'Trigo'
    TabOrder = 0
    OnClick = ButDegClick
  end
  object ButFow: TButton
    Left = 140
    Top = 184
    Width = 89
    Height = 57
    Caption = 'Avancer'
    TabOrder = 1
    OnClick = ButFowClick
  end
  object TrackDeg: TTrackBar
    Left = 95
    Top = 56
    Width = 186
    Height = 33
    Max = 360
    Min = 1
    Position = 180
    TabOrder = 2
    OnChange = TrackDegChange
  end
  object ButLef: TButton
    Left = 44
    Top = 272
    Width = 89
    Height = 57
    Caption = 'Gauche'
    TabOrder = 3
    OnClick = ButLefClick
  end
  object ButBack: TButton
    Left = 140
    Top = 360
    Width = 89
    Height = 57
    Caption = 'Reculer'
    TabOrder = 4
    OnClick = ButBackClick
  end
  object ButRig: TButton
    Left = 236
    Top = 272
    Width = 89
    Height = 57
    Caption = 'Droite'
    TabOrder = 5
    OnClick = ButRigClick
  end
  object ButHorr: TButton
    Left = 287
    Top = 56
    Width = 58
    Height = 57
    Caption = 'Horraire'
    TabOrder = 6
    OnClick = ButHorrClick
  end
  object TrackVitesse: TTrackBar
    Left = 424
    Top = 56
    Width = 313
    Height = 33
    Max = 100
    Min = 1
    Position = 50
    TabOrder = 7
    OnChange = TrackVitesseChange
  end
  object ButUp: TButton
    Left = 32
    Top = 472
    Width = 57
    Height = 57
    Caption = 'Monter'
    TabOrder = 8
    OnClick = ButUpClick
  end
  object TrackHauteur: TTrackBar
    Left = 95
    Top = 472
    Width = 187
    Height = 33
    Max = 500
    Min = 1
    Position = 50
    TabOrder = 9
    OnChange = TrackHauteurChange
  end
  object ButDown: TButton
    Left = 288
    Top = 472
    Width = 57
    Height = 57
    Caption = 'Descendre'
    TabOrder = 10
    OnClick = ButDownClick
  end
  object ButOff: TButton
    Left = 424
    Top = 472
    Width = 153
    Height = 57
    Caption = 'Decoller'
    TabOrder = 11
    OnClick = ButOffClick
  end
  object ButLand: TButton
    Left = 583
    Top = 472
    Width = 154
    Height = 57
    Caption = 'Atterrir'
    TabOrder = 12
    OnClick = ButLandClick
  end
  object ButCmd: TButton
    Left = 32
    Top = 544
    Width = 313
    Height = 25
    Caption = 'Commande'
    TabOrder = 13
    OnClick = ButCmdClick
  end
  object EditIP: TEdit
    Left = 424
    Top = 546
    Width = 313
    Height = 21
    Alignment = taCenter
    TabOrder = 14
    Text = '127.0.0.1'
  end
  object RichEdit1: TRichEdit
    Left = 760
    Top = 24
    Width = 329
    Height = 545
    Font.Charset = 254
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 15
    Zoom = 100
  end
  object ButDev: TButton
    Left = 717
    Top = 22
    Width = 20
    Height = 20
    Caption = '>>'
    TabOrder = 16
    OnClick = ButDevClick
  end
end