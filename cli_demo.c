#include <ncurses.h>
#include "vault.h"

void vaultOpen()
{
  printw("\nVault was opened\n");
  refresh();
}

void vaultClosed()
{
  printw("\nVault was closed\n");
  refresh();
}

int main()
{
  vault_t vault;
  Vault_init(&vault, vaultOpen, vaultClosed);
  uint8_t c;

  initscr();

  printw("Enter code: ");
  refresh();

  while(1) {
    c = (uint8_t) getch();
    Vault_inputCode(&vault, c);
  }

  endwin();
}
