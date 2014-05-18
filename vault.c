#include "vault.h"

void Vault_init(vault_t * vault, callback vault_open, callback vault_closed)
{
  vault->state = OPEN;
  vault->cb_open = vault_open;
  vault->cb_closed = vault_closed;
  vault->entered_codes = 0;
}

void Vault_inputCode(vault_t * vault, uint8_t code)
{
  switch(vault->state) {
    case OPEN:
      vault->password[vault->entered_codes] = code;
      vault->entered_codes++;

      if (vault->entered_codes == PASSWORD_LENGTH) {
        vault->state = CLOSED;
        vault->entered_codes = 0;
        vault->cb_closed();
      }
      break;
    case CLOSED:
      if(vault->password[vault->entered_codes] == code) {
        vault->entered_codes++;

        if (vault->entered_codes == PASSWORD_LENGTH) {
          vault->state = OPEN;
          vault->entered_codes = 0;
          vault->cb_open();
        }
      }
      else {
        vault->entered_codes = 0;
      }
      break;
  }
}
