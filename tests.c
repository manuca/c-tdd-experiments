#include "greatest.h"
#include "vault.h"

int vault_closed = 0;

void vaultClosed()
{
  vault_closed = 1;
}

void vaultOpened()
{
  vault_closed = 0;
}

TEST should_detect_valid_password()
{
  vault_t v;

  vault_closed = 0;
  ASSERT(!vault_closed);
  Vault_init(&v, vaultOpened, vaultClosed);
  Vault_inputCode(&v, 1);
  Vault_inputCode(&v, 1);
  Vault_inputCode(&v, 1);
  Vault_inputCode(&v, 1);
  ASSERT(vault_closed);
  Vault_inputCode(&v, 1);
  Vault_inputCode(&v, 1);
  Vault_inputCode(&v, 1);
  Vault_inputCode(&v, 1);
  ASSERT(!vault_closed);
  PASS();
}

TEST should_detect_invalid_password()
{
  vault_t v;

  vault_closed = 0;
  ASSERT(!vault_closed);
  Vault_init(&v, vaultOpened, vaultClosed);
  Vault_inputCode(&v, 1);
  Vault_inputCode(&v, 2);
  Vault_inputCode(&v, 3);
  Vault_inputCode(&v, 4);
  ASSERT(vault_closed);
  Vault_inputCode(&v, 4);
  Vault_inputCode(&v, 3);
  Vault_inputCode(&v, 2);
  Vault_inputCode(&v, 1);
  ASSERT(vault_closed);
  PASS();
}

SUITE(the_suite) {
  RUN_TEST(should_detect_valid_password);
  RUN_TEST(should_detect_invalid_password);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
  GREATEST_MAIN_BEGIN();
  RUN_SUITE(the_suite);
  GREATEST_MAIN_END();
}
