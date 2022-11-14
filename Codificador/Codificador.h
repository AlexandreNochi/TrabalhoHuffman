struct RegTable
{
  char symbol;
  int frequency;
  struct RegTabela *prox;
};
typedef struct RegTable TabFrequency;

void InitTab(TabFrequency **tab);
TabFrequency *createNodeFrequency(char symbol);
void insertTab(TabFrequency **tab, char symbol);
void orderTab(TabFrequency **tab);
char removeTab(TabFrequency **tab);

void InitTab(TabFrequency **tab)
{
  *tab = NULL;
}
TabFrequency *createNodeFrequency(char symbol)
{
  TabFrequency *no = (TabFrequency *)malloc(sizeof(TabFrequency));

  no->symbol = symbol;
  no->frequency = 1;
  no->prox = NULL;

  return no;
}
void insertTab(TabFrequency **tab, char symbol)
{
  TabFrequency *aux;

  if (*tab == NULL)
    *tab = createNodeFrequency(symbol);
  else
  {
    aux = *tab;
    while (aux->prox != NULL && aux->symbol != symbol)
      aux = aux->prox;

    if (aux->symbol == symbol)
    {
      aux->frequency++;
      orderTab(*tab);
    }
    else
      aux->prox = createNodeFrequency(symbol);
  }
}
void orderTab(TabFrequency **tab)
{
}
char removeTab(TabFrequency **tab)
{
  TabFrequency *aux;
  char symbol;

  if (*tab != NULL)
  {
    aux = *tab;

    while (aux->prox != NULL)
      aux = aux->prox;

    symbol = aux->symbol;
    free(aux);

    return symbol;
  }

  return -1;
}
