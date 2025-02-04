#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <kernaux/assert.h>
#include <kernaux/io.h>

#include <stddef.h>

struct KernAux_File KernAux_File_create(const KernAux_File_Out out)
{
    struct KernAux_File file;
    KernAux_File_init(&file, out);
    return file;
}

void KernAux_File_init(const KernAux_File file, const KernAux_File_Out out)
{
    KERNAUX_ASSERT(file);
    KERNAUX_ASSERT(out);

    file->out = out;
}
