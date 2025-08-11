# minix-bin-refactored-gpt-5

## Refactoring notes

- Introduced a tiny common input helper in `common/common.h` and adopted it where safe:
  - `read_yes_no_from_stdin()` centralizes y/n parsing.
  - `prompt_yes_no()`, `prompt_overwrite()`, `prompt_replace()` provide consistent prompts.

- Current adopters
  - `cp/` via `cp/utils.c`
  - `mv/mv.c`
  - `rm/rm.c` (uses the common y/n parser while preserving existing prompt text)

### Guidance for future changes
- Prefer using `common/common.h` helpers for interactive y/n flows.
- Keep prompts user-visible text consistent with historical behavior; swap only the input parsing to shared helpers when necessary.
