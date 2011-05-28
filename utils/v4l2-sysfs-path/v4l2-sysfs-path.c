/*
 * Copyright © 2011 Red Hat, Inc.
 *
 * Permission to use, copy, modify, distribute, and sell this software
 * and its documentation for any purpose is hereby granted without
 * fee, provided that the above copyright notice appear in all copies
 * and that both that copyright notice and this permission notice
 * appear in supporting documentation, and that the name of Red Hat
 * not be used in advertising or publicity pertaining to distribution
 * of the software without specific, written prior permission.  Red
 * Hat makes no representations about the suitability of this software
 * for any purpose.  It is provided "as is" without express or implied
 * warranty.
 *
 * THE AUTHORS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN
 * NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * Author:
 * 	Mauro Carvalho Chehab <mchehab@redhat.com>
 */

#include "../libmedia_dev/get_media_devices.h"
#include <stdio.h>

int main(void)
{
	void *md;
	char *alsa;

	md = discover_media_devices();
	display_media_devices(md);

	alsa = get_associated_device(md, NULL, SND_CAP, "video0", V4L_VIDEO);
	if (alsa)
		printf("Alsa device associated with video0 capture: %s\n", alsa);

	alsa = get_not_associated_device(md, NULL, SND_OUT, V4L_VIDEO);
	if (alsa)
		printf("Alsa output device: %s\n", alsa);

	free_media_devices(md);

	return 0;
}
