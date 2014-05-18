#include <stdint.h>

#define PASSWORD_LENGTH 4
enum door_state { OPEN, CLOSED };

typedef void (* callback)(void);
typedef enum door_state door_state_t;
typedef struct vault_s {
  door_state_t state;
  callback cb_open;
  callback cb_closed;
  uint8_t password[4];
  uint8_t entered_codes;
} vault_t;

void Vault_init(vault_t * vault, callback vault_open, callback vault_closed);
void Vault_inputCode(vault_t * vault, uint8_t code);
