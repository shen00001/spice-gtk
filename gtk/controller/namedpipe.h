/*
   Copyright (C) 2011 Red Hat, Inc.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __NAMED_PIPE_H__
#define __NAMED_PIPE_H__

#include <gio/gio.h>

G_BEGIN_DECLS

#define SPICE_TYPE_NAMED_PIPE                       (spice_named_pipe_get_type ())
#define SPICE_NAMED_PIPE(inst)                      (G_TYPE_CHECK_INSTANCE_CAST ((inst),                     \
                                                     SPICE_TYPE_NAMED_PIPE, SpiceNamedPipe))
#define SPICE_NAMED_PIPE_CLASS(class)               (G_TYPE_CHECK_CLASS_CAST ((class),                       \
                                                     SPICE_TYPE_NAMED_PIPE, SpiceNamedPipeClass))
#define SPICE_IS_NAMED_PIPE(inst)                   (G_TYPE_CHECK_INSTANCE_TYPE ((inst),                     \
                                                     SPICE_TYPE_NAMED_PIPE))
#define SPICE_IS_NAMED_PIPE_CLASS(class)            (G_TYPE_CHECK_CLASS_TYPE ((class),                       \
                                                     SPICE_TYPE_NAMED_PIPE))
#define SPICE_NAMED_PIPE_GET_CLASS(inst)            (G_TYPE_INSTANCE_GET_CLASS ((inst),                      \
                                                     SPICE_TYPE_NAMED_PIPE, SpiceNamedPipeClass))

typedef struct _SpiceNamedPipe                       SpiceNamedPipe;
typedef struct _SpiceNamedPipePrivate                SpiceNamedPipePrivate;
typedef struct _SpiceNamedPipeClass                  SpiceNamedPipeClass;

struct _SpiceNamedPipeClass
{
  GObjectClass parent_class;
};

struct _SpiceNamedPipe
{
  GObject parent_instance;
  SpiceNamedPipePrivate *priv;
};

GType            spice_named_pipe_get_type  (void) G_GNUC_CONST;

SpiceNamedPipe * spice_named_pipe_new       (const gchar *name);

#define SPICE_TYPE_NAMED_PIPE_CONNECTION                     (spice_named_pipe_connection_get_type ())
#define SPICE_NAMED_PIPE_CONNECTION(inst)                    (G_TYPE_CHECK_INSTANCE_CAST ((inst), \
                                                              SPICE_TYPE_NAMED_PIPE_CONNECTION, SpiceNamedPipeConnection))
#define SPICE_NAMED_PIPE_CONNECTION_CLASS(class)             (G_TYPE_CHECK_CLASS_CAST ((class),                       \
                                                              SPICE_TYPE_NAMED_PIPE_CONNECTION, SpiceNamedPipeConnectionClass))
#define SPICE_IS_NAMED_PIPE_CONNECTION(inst)                 (G_TYPE_CHECK_INSTANCE_TYPE ((inst),                     \
                                                              SPICE_TYPE_NAMED_PIPE_CONNECTION))
#define SPICE_IS_NAMED_PIPE_CONNECTION_CLASS(class)          (G_TYPE_CHECK_CLASS_TYPE ((class),                       \
                                                              SPICE_TYPE_NAMED_PIPE_CONNECTION))
#define SPICE_NAMED_PIPE_CONNECTION_GET_CLASS(inst)          (G_TYPE_INSTANCE_GET_CLASS ((inst),                      \
                                                              SPICE_TYPE_NAMED_PIPE_CONNECTION, SpiceNamedPipeConnectionClass))

typedef struct _SpiceNamedPipeConnection                     SpiceNamedPipeConnection;
typedef struct _SpiceNamedPipeConnectionPrivate              SpiceNamedPipeConnectionPrivate;
typedef struct _SpiceNamedPipeConnectionClass                SpiceNamedPipeConnectionClass;

struct _SpiceNamedPipeConnectionClass
{
  GSocketConnectionClass parent_class;
};

struct _SpiceNamedPipeConnection
{
  GSocketConnection parent_instance;
  SpiceNamedPipeConnectionPrivate *priv;
};

GType    spice_named_pipe_connection_get_type                (void) G_GNUC_CONST;

#define SPICE_TYPE_NAMED_PIPE_LISTENER                       (spice_named_pipe_listener_get_type ())
#define SPICE_NAMED_PIPE_LISTENER(inst)                      (G_TYPE_CHECK_INSTANCE_CAST ((inst),                     \
                                                              SPICE_TYPE_NAMED_PIPE_LISTENER, SpiceNamedPipeListener))
#define SPICE_NAMED_PIPE_LISTENER_CLASS(class)               (G_TYPE_CHECK_CLASS_CAST ((class),                       \
                                                              SPICE_TYPE_NAMED_PIPE_LISTENER, SpiceNamedPipeListenerClass))
#define SPICE_IS_NAMED_PIPE_LISTENER(inst)                   (G_TYPE_CHECK_INSTANCE_TYPE ((inst),                     \
                                                              SPICE_TYPE_NAMED_PIPE_LISTENER))
#define SPICE_IS_NAMED_PIPE_LISTENER_CLASS(class)            (G_TYPE_CHECK_CLASS_TYPE ((class),                       \
                                                              SPICE_TYPE_NAMED_PIPE_LISTENER))
#define SPICE_NAMED_PIPE_LISTENER_GET_CLASS(inst)            (G_TYPE_INSTANCE_GET_CLASS ((inst),                      \
                                                              SPICE_TYPE_NAMED_PIPE_LISTENER, SpiceNamedPipeListenerClass))

typedef struct _SpiceNamedPipeListener                       SpiceNamedPipeListener;
typedef struct _SpiceNamedPipeListenerPrivate                SpiceNamedPipeListenerPrivate;
typedef struct _SpiceNamedPipeListenerClass                  SpiceNamedPipeListenerClass;

struct _SpiceNamedPipeListenerClass
{
  GSocketListenerClass parent_class;
};

struct _SpiceNamedPipeListener
{
  GSocketListener parent_instance;
  SpiceNamedPipeListenerPrivate *priv;
};

GType                       spice_named_pipe_listener_get_type       (void) G_GNUC_CONST;

SpiceNamedPipeListener *    spice_named_pipe_listener_new            (void);
void                        spice_named_pipe_listener_add_named_pipe (SpiceNamedPipeListener  *listener,
                                                                      SpiceNamedPipe          *namedpipe);
void                        spice_named_pipe_listener_accept_async   (SpiceNamedPipeListener *listener,
                                                                      GCancellable           *cancellable,
                                                                      GAsyncReadyCallback     callback,
                                                                      gpointer                user_data);
GSocketConnection *         spice_named_pipe_listener_accept_finish  (SpiceNamedPipeListener *listener,
                                                                      GAsyncResult           *result,
                                                                      GObject               **source_object,
                                                                      GError                **error);

G_END_DECLS

#endif /* __NAMED_PIPE_H__ */