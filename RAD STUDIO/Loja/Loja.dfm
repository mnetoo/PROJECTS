object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'SISTEMA DE VENDAS'
  ClientHeight = 399
  ClientWidth = 831
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Panel1: TPanel
    Left = -12
    Top = -8
    Width = 148
    Height = 425
    TabOrder = 0
    object BitBtn1: TBitBtn
      Left = 24
      Top = 41
      Width = 105
      Height = 57
      Caption = 'Produtos'
      TabOrder = 0
      OnClick = BitBtn1Click
    end
    object BitBtn2: TBitBtn
      Left = 24
      Top = 104
      Width = 105
      Height = 54
      Caption = 'Estoque'
      TabOrder = 1
      OnClick = BitBtn2Click
    end
    object BitBtn3: TBitBtn
      Left = 24
      Top = 164
      Width = 105
      Height = 56
      Caption = 'Clientes'
      TabOrder = 2
      OnClick = BitBtn3Click
    end
    object BitBtn4: TBitBtn
      Left = 24
      Top = 226
      Width = 105
      Height = 59
      Caption = 'Vendas'
      TabOrder = 3
      OnClick = BitBtn4Click
    end
    object BitBtn12: TBitBtn
      Left = 24
      Top = 291
      Width = 105
      Height = 59
      Caption = 'Hist'#243'rico'
      TabOrder = 4
      OnClick = BitBtn12Click
    end
  end
  object PageControl1: TPageControl
    Left = 136
    Top = 0
    Width = 756
    Height = 400
    ActivePage = TabSheet2
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'Produtos'
      object Label1: TLabel
        Left = 24
        Top = 104
        Width = 99
        Height = 15
        Caption = 'Nome do produto:'
      end
      object Label2: TLabel
        Left = 241
        Top = 104
        Width = 96
        Height = 15
        Caption = 'Pre'#231'o do produto:'
      end
      object Label3: TLabel
        Left = 457
        Top = 104
        Width = 128
        Height = 15
        Caption = 'Quantidade do produto:'
      end
      object Edit1: TEdit
        Left = 24
        Top = 125
        Width = 193
        Height = 23
        TabOrder = 0
      end
      object Edit2: TEdit
        Left = 240
        Top = 125
        Width = 193
        Height = 23
        TabOrder = 1
      end
      object BitBtn5: TBitBtn
        Left = 256
        Top = 212
        Width = 169
        Height = 77
        Caption = 'Cadastrar Produto'
        TabOrder = 2
        OnClick = BitBtn5Click
      end
      object Edit3: TEdit
        Left = 457
        Top = 125
        Width = 193
        Height = 23
        TabOrder = 3
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Estoque'
      ImageIndex = 2
      object StringGrid1: TStringGrid
        Left = 40
        Top = 24
        Width = 617
        Height = 329
        ColCount = 3
        DefaultColWidth = 203
        FixedCols = 0
        RowCount = 1
        FixedRows = 0
        TabOrder = 0
      end
    end
    object TabSheet7: TTabSheet
      Caption = 'Clientes'
      ImageIndex = 6
      object Label4: TLabel
        Left = 24
        Top = 17
        Width = 93
        Height = 15
        Caption = 'Nome do Cliente:'
      end
      object Label5: TLabel
        Left = 304
        Top = 17
        Width = 24
        Height = 15
        Caption = 'CPF:'
      end
      object Label6: TLabel
        Left = 24
        Top = 89
        Width = 110
        Height = 15
        Caption = 'Data de Nascimento:'
      end
      object Label7: TLabel
        Left = 304
        Top = 89
        Width = 47
        Height = 15
        Caption = 'Telefone:'
      end
      object Edit4: TEdit
        Left = 24
        Top = 38
        Width = 239
        Height = 23
        TabOrder = 0
      end
      object Edit5: TEdit
        Left = 304
        Top = 38
        Width = 239
        Height = 23
        TabOrder = 1
      end
      object DateTimePicker1: TDateTimePicker
        Left = 24
        Top = 110
        Width = 239
        Height = 23
        Date = 45678.000000000000000000
        Time = 0.904158530094719000
        TabOrder = 2
      end
      object Edit6: TEdit
        Left = 304
        Top = 110
        Width = 241
        Height = 23
        TabOrder = 3
      end
      object BitBtn6: TBitBtn
        Left = 560
        Top = 47
        Width = 113
        Height = 58
        Caption = 'Cadastrar Cliente'
        TabOrder = 4
        OnClick = BitBtn6Click
      end
      object StringGrid2: TStringGrid
        Left = 24
        Top = 184
        Width = 649
        Height = 161
        ColCount = 4
        DefaultColWidth = 160
        FixedCols = 0
        RowCount = 1
        FixedRows = 0
        TabOrder = 5
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Vendas'
      ImageIndex = 3
      object Label8: TLabel
        Left = 24
        Top = 26
        Width = 40
        Height = 15
        Caption = 'Cliente:'
      end
      object Label9: TLabel
        Left = 24
        Top = 110
        Width = 46
        Height = 15
        Caption = 'Produto:'
      end
      object Label10: TLabel
        Left = 281
        Top = 110
        Width = 91
        Height = 15
        Caption = 'Qntd. Dispon'#237'vel:'
      end
      object Label11: TLabel
        Left = 408
        Top = 110
        Width = 83
        Height = 15
        Caption = 'Qntd. Desejada:'
      end
      object Label12: TLabel
        Left = 535
        Top = 110
        Width = 28
        Height = 15
        Caption = 'Total:'
      end
      object Label13: TLabel
        Left = 215
        Top = 110
        Width = 33
        Height = 15
        Caption = 'Pre'#231'o:'
      end
      object Label14: TLabel
        Left = 215
        Top = 26
        Width = 24
        Height = 15
        Caption = 'CPF:'
      end
      object Label15: TLabel
        Left = 343
        Top = 26
        Width = 32
        Height = 15
        Caption = 'Idade:'
      end
      object Label16: TLabel
        Left = 470
        Top = 26
        Width = 47
        Height = 15
        Caption = 'Telefone:'
      end
      object Label17: TLabel
        Left = 459
        Top = 318
        Width = 114
        Height = 15
        Caption = 'Valor Total do Pedido:'
      end
      object ComboBox1: TComboBox
        Left = 25
        Top = 47
        Width = 185
        Height = 23
        TabOrder = 0
        OnChange = ComboBox1Change
      end
      object Edit7: TEdit
        Left = 216
        Top = 47
        Width = 121
        Height = 23
        TabOrder = 1
      end
      object Edit8: TEdit
        Left = 343
        Top = 47
        Width = 121
        Height = 23
        TabOrder = 2
      end
      object Edit9: TEdit
        Left = 470
        Top = 47
        Width = 121
        Height = 23
        TabOrder = 3
      end
      object ComboBox2: TComboBox
        Left = 24
        Top = 131
        Width = 185
        Height = 23
        TabOrder = 4
        OnChange = ComboBox2Change
      end
      object Edit10: TEdit
        Left = 215
        Top = 131
        Width = 60
        Height = 23
        TabOrder = 5
      end
      object Edit11: TEdit
        Left = 281
        Top = 131
        Width = 121
        Height = 23
        TabOrder = 6
      end
      object Edit12: TEdit
        Left = 408
        Top = 131
        Width = 121
        Height = 23
        TabOrder = 7
        OnChange = Edit12Change
      end
      object BitBtn8: TBitBtn
        Left = 608
        Top = 81
        Width = 75
        Height = 38
        Caption = 'Novo'#13#10'Produto'
        TabOrder = 8
        OnClick = BitBtn8Click
      end
      object BitBtn7: TBitBtn
        Left = 608
        Top = 37
        Width = 75
        Height = 38
        Caption = 'Novo'#13#10'Cliente'
        TabOrder = 9
        OnClick = BitBtn7Click
      end
      object StringGrid3: TStringGrid
        Left = 16
        Top = 184
        Width = 665
        Height = 121
        ColCount = 4
        DefaultColWidth = 162
        FixedCols = 0
        RowCount = 1
        FixedRows = 0
        TabOrder = 10
      end
      object Edit13: TEdit
        Left = 535
        Top = 131
        Width = 60
        Height = 23
        TabOrder = 11
      end
      object BitBtn9: TBitBtn
        Left = 608
        Top = 125
        Width = 75
        Height = 38
        Caption = 'Adicionar'#13#10'Produto'
        TabOrder = 12
        OnClick = BitBtn9Click
      end
      object BitBtn10: TBitBtn
        Left = 606
        Top = 323
        Width = 75
        Height = 39
        Caption = 'Finalizar'#13#10'Pedido'
        TabOrder = 13
        OnClick = BitBtn10Click
      end
      object Edit14: TEdit
        Left = 459
        Top = 339
        Width = 134
        Height = 23
        TabOrder = 14
      end
    end
    object TTabSheet
      Caption = 'Hist'#243'rico'
      ImageIndex = 4
      object Label18: TLabel
        Left = 113
        Top = 19
        Width = 40
        Height = 15
        Caption = 'Cliente:'
      end
      object StringGrid4: TStringGrid
        Left = 113
        Top = 89
        Width = 448
        Height = 128
        ColCount = 4
        DefaultColWidth = 110
        FixedCols = 0
        RowCount = 1
        FixedRows = 0
        TabOrder = 0
      end
      object Edit15: TEdit
        Left = 113
        Top = 40
        Width = 216
        Height = 23
        TabOrder = 1
      end
      object BitBtn11: TBitBtn
        Left = 406
        Top = 40
        Width = 75
        Height = 23
        Caption = 'Pesquisar'
        TabOrder = 2
        OnClick = BitBtn11Click
      end
      object BitBtn13: TBitBtn
        Left = 486
        Top = 40
        Width = 75
        Height = 24
        Caption = 'Limpar'
        TabOrder = 3
        OnClick = BitBtn13Click
      end
    end
  end
end
